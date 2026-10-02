#include <iostream>
#include <string>
#include <limits>

using namespace std;

constexpr int MAX_SPECIALIZATIONS = 20;
constexpr int MAX_PATIENTS = 5;

struct Patient {
    string name;
    int status; // 0 = regular, 1 = urgent
};

struct Specialization {
    Patient patients[MAX_PATIENTS];
    int count = 0;
};

struct HospitalSystem {
    Specialization specializations[MAX_SPECIALIZATIONS];
};

int readInt(const string& message)
{
    int value;

    while (true)
    {
        cout << message;

        if (cin >> value)
            return value;

        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void addPatient(HospitalSystem& system)
{
    const int specialization = readInt("Enter specialization (1-20): ");

    if (specialization < 1 || specialization > MAX_SPECIALIZATIONS)
    {
        cout << "Invalid specialization.\n";
        return;
    }

    const int index = specialization - 1;
    Specialization& queue = system.specializations[index];

    if (queue.count >= MAX_PATIENTS)
    {
        cout << "This specialization is full.\n";
        return;
    }

    string name;
    cout << "Enter patient name: ";
    cin >> name;

    int status;
    do
    {
        status = readInt("Enter status (0 = regular, 1 = urgent): ");

        if (status != 0 && status != 1)
            cout << "Status must be 0 or 1.\n";
    }
    while (status != 0 && status != 1);

    if (status == 1)
    {
        for (int i = queue.count; i > 0; --i)
            queue.patients[i] = queue.patients[i - 1];

        queue.patients[0] = {name, status};
    }
    else
    {
        queue.patients[queue.count] = {name, status};
    }

    ++queue.count;
    cout << "Patient added successfully.\n";
}

void printPatients(const HospitalSystem& system)
{
    bool hasPatients = false;

    cout << "\n========== PATIENTS ==========\n";

    for (int i = 0; i < MAX_SPECIALIZATIONS; ++i)
    {
        const Specialization& queue = system.specializations[i];

        if (queue.count == 0)
            continue;

        hasPatients = true;

        cout << "\nSpecialization " << (i + 1)
             << " (" << queue.count << " patient(s))\n";

        for (int j = 0; j < queue.count; ++j)
        {
            cout << "  " << (j + 1) << ". "
                 << queue.patients[j].name
                 << " - "
                 << (queue.patients[j].status == 1 ? "Urgent" : "Regular")
                 << '\n';
        }
    }

    if (!hasPatients)
        cout << "No patients currently waiting.\n";

    cout << "==============================\n";
}

void getNextPatient(HospitalSystem& system)
{
    const int specialization = readInt("Enter specialization (1-20): ");

    if (specialization < 1 || specialization > MAX_SPECIALIZATIONS)
    {
        cout << "Invalid specialization.\n";
        return;
    }

    const int index = specialization - 1;
    Specialization& queue = system.specializations[index];

    if (queue.count == 0)
    {
        cout << "No patient is waiting in this specialization.\n";
        return;
    }

    cout << queue.patients[0].name
         << ", please go with the doctor.\n";

    for (int i = 0; i < queue.count - 1; ++i)
        queue.patients[i] = queue.patients[i + 1];

    --queue.count;
}

void showMenu()
{
    cout << "\n========== HOSPITAL SYSTEM ==========\n";
    cout << "1. Add new patient\n";
    cout << "2. Print all patients\n";
    cout << "3. Get next patient\n";
    cout << "4. Exit\n";
    cout << "=====================================\n";
}

int main()
{
    HospitalSystem system;
    int choice;

    do
    {
        showMenu();
        choice = readInt("Enter your choice: ");
        cout << '\n';

        switch (choice)
        {
            case 1:
                addPatient(system);
                break;

            case 2:
                printPatients(system);
                break;

            case 3:
                getNextPatient(system);
                break;

            case 4:
                cout << "Exiting Hospital System...\n";
                break;

            default:
                cout << "Please choose a number from 1 to 4.\n";
        }

    } while (choice != 4);

    return 0;
}
