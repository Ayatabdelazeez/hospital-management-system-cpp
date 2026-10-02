Hospital Management System – C++

Project Overview

A simple console-based Hospital Management System developed in C++.

The system is designed to manage patients, organize waiting queues by medical specialization, and handle regular and urgent patients efficiently.

This project is a refactored and organized version of the original hospital patient-management concept, while keeping the same main purpose and core functionality.

Features

Add new patients.

Assign patients to a medical specialization.

Set patient status as Regular or Urgent.

Give priority to urgent patients in the waiting queue.

Display all currently registered patients.

Call the next patient for a specific specialization.

Validate user input.

Simple and easy-to-use console interface.

Technologies

C++

Structs

Arrays

Functions

Input Validation

Console Application

How to Run

Using g++

g++ Hospital_Management_Refactored.cpp -o hospital
./hospital

Windows

g++ Hospital_Management_Refactored.cpp -o hospital.exe
hospital.exe

How It Works

When the program starts, the main menu is displayed:

========== HOSPITAL SYSTEM ==========
1. Add new patient
2. Print all patients
3. Get next patient
4. Exit
=====================================

1. Add New Patient

Adds a new patient by entering:

Specialization number

Patient name

Patient status

Urgent patients are placed at the front of the queue.

2. Print All Patients

Displays the patients currently waiting in each specialization.

3. Get Next Patient

Calls the next patient from a selected specialization and removes them from the waiting queue.

4. Exit

Closes the application.

Project Structure

hospital-management-system-cpp/
│
├── Hospital_Management_Refactored.cpp
└── README.md

Project Goal

The goal of this project is to apply fundamental C++ programming concepts by building a practical hospital patient-management system with organized queues and input validation.

Note

This repository contains a refactored version of the hospital patient-management system. The code was reorganized to improve readability, structure, and input handling while preserving the project's main purpose.
