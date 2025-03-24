# CAN-TO-C++-2025

This is a UI interface for Team Sunergy of Appalachian State.

It allows a Raspberry Pi to read and display CAN messages using 
Qt via C++. It may only be edited using Qt Creator, or other IDEs
with access to Qt Designer.

This is a continuation of the ROSE-CAN-to-Pi-2024 project by:
- Nathan Care
- John Waugh
- Blaez Jibben
- Sean Choi

A lot of the work in this initial commit is essentially a Python-Qt
translation of theirs, so they deserve credit.

## Repo

The project repository is available at .

## Features and Objectives (Current)

-   :( 

## Features and Objectives (Planned)

- Interface the Pi with the CAN bus
- Recieve CAN messages
- Display data to driver and passengers
- Support for mobile
- User-friendly interface
- Readable, maintainable code

## Conventions 

To ensure consistency and maintainability, included is a list of 
design conventions. Please comment instances where these conventions
are broken.

- Fonts are set **locally**, meaning they are set for each object, not
on the main window. 

## Contributors

Work mainly done by Alex Caldwell, with all other contributions noted
in-line using comments or in the README.
