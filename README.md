# Food Ordering System

## Overview
The Food Ordering System is designed to streamline hotel operations by providing functionalities for customers and hotel owners. It includes features such as user registration, authentication, menu customization, and time slot management. The system ensures secure handling of user data through object-oriented programming principles.


## System Components
### 1. Customer Management
- User registration and authentication
- Viewing available hotels and menus

### 2. Hotel Owner Management
- Registration of new hotels
- Authentication and updating hotel details
- Managing menu items and time slots

## Flowchart Representation
A flowchart is used to represent the interactions between customers, hotel owners, and the system.

## Features
### 1. File Handling
- **New Owner**: Stores new owner details.
- **Existing Owner**: Authenticates and updates details.
- **Existing Customer**: Authenticates using stored data.

### 2. Data Encapsulation
- Ensures secure handling of customer and owner data.
- Menu items are encapsulated to restrict unauthorized modifications.

### 3. Abstraction
- Hides sensitive customer data from hotel owners.
- Allows hotel owners to manage menus and time slots without accessing personal data.

### 4. Operator Overloading
- Used for better representation and formatting of menu data.

### 5. Class Composition
- The `ExistingOwner` class manages different menu categories using composition.
- Categories include MainCourse, Starter, Dessert, and Snacks.

### 6. Inheritance
- **Multiple Inheritance**: `Starter` and `Dessert` classes inherit from both `Lunch` and `Dinner`.
- **Multi-Level Inheritance**: `Item` is a base class for `Breakfast`, `Lunch`, and `Dinner`, with further inheritance from `MainCourse` and `Starter`.

### 7. Virtual Base Class
- `Item` is used as a virtual base class to prevent duplication in inheritance.

### 8. Polymorphism
- The `Item` class contains a pure virtual function `courseType()`.
- `MainCourse`, `Starter`, and `Dessert` override this function to specify their course types.

## Technologies Used
- C++ for implementation
- File handling for data storage
- Object-Oriented Programming (OOP) principles

## How to Use
1. **Compile the Code**: Ensure that all required files are present.
2. **Run the System**: Execute the main program to interact with the system.
3. **Register/Login**: Customers and owners can register and log in to access their respective functionalities.
4. **Manage Menus**: Owners can customize menu items and time slots.

## Future Improvements
- Integration with a database for better data management.
- Web-based interface for easier access.
- Enhanced security features.

## License
This project is for educational purposes only.

---

Feel free to contribute or suggest improvements!

