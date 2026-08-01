#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void enableColors()
{ 
   
}

const int MAX = 100;

struct Donor {
    int id;
    string name;
    int age;
    string bloodGroup;
    string phone;
};

Donor donors[MAX];
int totalDonors = 0;
int nextID = 1001;

void addDonor() {

    donors[totalDonors].id = nextID++;

    if (totalDonors == MAX) {
        cout << RED << "\nBlood bank is full!\n" << RESET;
        return;
    }

    cout << CYAN << BOLD << "\n--- Add Donor ---\n" << RESET;

    cin.ignore();

    cout << YELLOW << "Enter Name: " << RESET;
    getline(cin, donors[totalDonors].name);

    do {
        cout << YELLOW << "Enter Age (18-65): " << RESET;
        cin >> donors[totalDonors].age;

        if (donors[totalDonors].age < 18 || donors[totalDonors].age > 65)
            cout << RED << "Invalid Age! Try Again.\n" << RESET;

    } while (donors[totalDonors].age < 18 || donors[totalDonors].age > 65);

    do {

        cout << YELLOW << "Enter Blood Group (A+, A-, B+, B-, AB+, AB-, O+, O-): " << RESET;
        cin >> donors[totalDonors].bloodGroup;

        if (donors[totalDonors].bloodGroup != "A+" &&
            donors[totalDonors].bloodGroup != "A-" &&
            donors[totalDonors].bloodGroup != "B+" &&
            donors[totalDonors].bloodGroup != "B-" &&
            donors[totalDonors].bloodGroup != "AB+" &&
            donors[totalDonors].bloodGroup != "AB-" &&
            donors[totalDonors].bloodGroup != "O+" &&
            donors[totalDonors].bloodGroup != "O-")
        {
            cout << RED << "Invalid Blood Group!\n" << RESET;
        }

    } while (
        donors[totalDonors].bloodGroup != "A+" &&
        donors[totalDonors].bloodGroup != "A-" &&
        donors[totalDonors].bloodGroup != "B+" &&
        donors[totalDonors].bloodGroup != "B-" &&
        donors[totalDonors].bloodGroup != "AB+" &&
        donors[totalDonors].bloodGroup != "AB-" &&
        donors[totalDonors].bloodGroup != "O+" &&
        donors[totalDonors].bloodGroup != "O-"
    );

    do {

        cout << YELLOW << "Enter 10-digit Phone Number: " << RESET;
        cin >> donors[totalDonors].phone;

        for (int i = 0; i < totalDonors; i++) {

            if (donors[i].name == donors[totalDonors].name &&
                donors[i].phone == donors[totalDonors].phone) {

                cout << RED << "\nDonor already exists!\n" << RESET;
                return;
            }
        }

        if (donors[totalDonors].phone.length() != 10)
            cout << RED << "Invalid Phone Number!\n" << RESET;
    

    } while (donors[totalDonors].phone.length() != 10);

    totalDonors++;

    cout << GREEN << "\nDonor added successfully!\n" << RESET;
}

void viewDonors() {

    if (totalDonors == 0) {
        cout << RED << "\nNo donor records found.\n" << RESET;
        return;
    }

    cout << CYAN << "\n===================================================================================\n" << RESET;

    cout << BOLD << WHITE << left
         << setw(8) << "ID"
         << setw(20) << "Name"
         << setw(8) << "Age"
         << setw(15) << "Blood Group"
         << setw(15) << "Phone"
         << RESET << endl;

    cout << CYAN << "===================================================================================\n" << RESET;

    for (int i = 0; i < totalDonors; i++) {

        cout << left
             << setw(8) << donors[i].id
             << setw(20) << donors[i].name
             << setw(8) << donors[i].age
             << MAGENTA << setw(15) << donors[i].bloodGroup << RESET
             << setw(15) << donors[i].phone
             << endl;
    }

    cout << CYAN << "===================================================================================\n" << RESET;
}

void searchBloodGroup() {
    if (totalDonors == 0) {
        cout << RED << "\nNo donor records found.\n" << RESET;
        return;
    }

    string group;
    bool found = false;

    cout << YELLOW << "\nEnter Blood Group to Search: " << RESET;
    cin >> group;

    cout << CYAN << "\nMatching Donors:\n" << RESET;

    for (int i = 0; i < totalDonors; i++) {
        if (donors[i].bloodGroup == group) {
            cout << "\n" << BOLD << "Name  : " << RESET << donors[i].name << endl;
            cout << BOLD << "Age   : " << RESET << donors[i].age << endl;
            cout << BOLD << "Phone : " << RESET << donors[i].phone << endl;
            found = true;
        }
    }

    if (!found)
        cout << RED << "No donor found with blood group " << group << RESET << endl;
}

void searchByName() {
    if (totalDonors == 0) {
        cout << RED << "\nNo donor records found.\n" << RESET;
        return;
    }

    string name;
    bool found = false;

    cin.ignore();

    cout << YELLOW << "\nEnter Donor Name: " << RESET;
    getline(cin, name);

    for (int i = 0; i < totalDonors; i++) {

        if (donors[i].name == name) {

            cout << GREEN << "\nDonor Found\n" << RESET;
            cout << CYAN << "---------------------\n" << RESET;
            cout << BOLD << "Name        : " << RESET << donors[i].name << endl;
            cout << BOLD << "Age         : " << RESET << donors[i].age << endl;
            cout << BOLD << "Blood Group : " << RESET << MAGENTA << donors[i].bloodGroup << RESET << endl;
            cout << BOLD << "Phone       : " << RESET << donors[i].phone << endl;

            found = true;
        }
    }

    if (!found) {
        cout << RED << "\nDonor not found.\n" << RESET;
    }
}

void deleteDonor() {
    if (totalDonors == 0) {
        cout << RED << "\nNo donor records found.\n" << RESET;
        return;
    }

    string name;
    bool found = false;

    cin.ignore();

    cout << YELLOW << "\nEnter Donor Name to Delete: " << RESET;
    getline(cin, name);

    for (int i = 0; i < totalDonors; i++) {
        if (donors[i].name == name) {

            for (int j = i; j < totalDonors - 1; j++) {
                donors[j] = donors[j + 1];
            }

            totalDonors--;

            cout << GREEN << "\nDonor deleted successfully!\n" << RESET;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << RED << "\nDonor not found.\n" << RESET;
    }
}

void updateDonor() {
    if (totalDonors == 0) {
        cout << RED << "\nNo donor records found.\n" << RESET;
        return;
    }

    string name;
    bool found = false;

    cin.ignore();

    cout << YELLOW << "\nEnter Donor Name to Update: " << RESET;
    getline(cin, name);

    for (int i = 0; i < totalDonors; i++) {

        if (donors[i].name == name) {

            found = true;

            int choice;

            do {

                cout << CYAN << BOLD << "\n===== Update Menu =====\n" << RESET;
                cout << "1. Name\n";
                cout << "2. Age\n";
                cout << "3. Blood Group\n";
                cout << "4. Phone Number\n";
                cout << "5. Update All Details\n";
                cout << "6. Exit\n";
                cout << YELLOW << "Enter choice: " << RESET;
                cin >> choice;

                cin.ignore();

                switch (choice) {

                case 1:
                    cout << YELLOW << "Enter New Name: " << RESET;
                    getline(cin, donors[i].name);
                    cout << GREEN << "Name updated successfully!\n" << RESET;
                    break;

                case 2:
                    cout << YELLOW << "Enter New Age: " << RESET;
                    cin >> donors[i].age;
                    cout << GREEN << "Age updated successfully!\n" << RESET;
                    break;

                case 3:
                    cout << YELLOW << "Enter New Blood Group: " << RESET;
                    cin >> donors[i].bloodGroup;
                    cout << GREEN << "Blood Group updated successfully!\n" << RESET;
                    break;

                case 4:
                    cout << YELLOW << "Enter New Phone Number: " << RESET;
                    cin >> donors[i].phone;
                    cout << GREEN << "Phone Number updated successfully!\n" << RESET;
                    break;

                case 5:
                    cout << YELLOW << "Enter New Name: " << RESET;
                    getline(cin, donors[i].name);

                    cout << YELLOW << "Enter New Age: " << RESET;
                    cin >> donors[i].age;

                    cout << YELLOW << "Enter New Blood Group: " << RESET;
                    cin >> donors[i].bloodGroup;

                    cout << YELLOW << "Enter New Phone Number: " << RESET;
                    cin >> donors[i].phone;

                    cout << GREEN << "\nAll details updated successfully!\n" << RESET;
                    break;

                case 6:
                    cout << BLUE << "Returning to Main Menu...\n" << RESET;
                    break;

                default:
                    cout << RED << "Invalid choice!\n" << RESET;
                }

            } while (choice != 6);

            break;
        }
    }

    if (!found) {
        cout << RED << "\nDonor not found.\n" << RESET;
    }
}

void bloodGroupStatistics() {

    if (totalDonors == 0) {
        cout << RED << "\nNo donor records found.\n" << RESET;
        return;
    }

    int Apos = 0, Aneg = 0;
    int Bpos = 0, Bneg = 0;
    int ABpos = 0, ABneg = 0;
    int Opos = 0, Oneg = 0;

    for (int i = 0; i < totalDonors; i++) {

        if (donors[i].bloodGroup == "A+")
            Apos++;

        else if (donors[i].bloodGroup == "A-")
            Aneg++;

        else if (donors[i].bloodGroup == "B+")
            Bpos++;

        else if (donors[i].bloodGroup == "B-")
            Bneg++;

        else if (donors[i].bloodGroup == "AB+")
            ABpos++;

        else if (donors[i].bloodGroup == "AB-")
            ABneg++;

        else if (donors[i].bloodGroup == "O+")
            Opos++;

        else if (donors[i].bloodGroup == "O-")
            Oneg++;
    }

    cout << CYAN << BOLD << "\n===== Blood Group Statistics =====\n" << RESET;
    cout << MAGENTA << "A+  : " << RESET << Apos << endl;
    cout << MAGENTA << "A-  : " << RESET << Aneg << endl;
    cout << MAGENTA << "B+  : " << RESET << Bpos << endl;
    cout << MAGENTA << "B-  : " << RESET << Bneg << endl;
    cout << MAGENTA << "AB+ : " << RESET << ABpos << endl;
    cout << MAGENTA << "AB- : " << RESET << ABneg << endl;
    cout << MAGENTA << "O+  : " << RESET << Opos << endl;
    cout << MAGENTA << "O-  : " << RESET << Oneg << endl;
}

void saveToFile() {

    ofstream file("donors.txt");

    if (!file) {
        cout << RED << "Unable to save file.\n" << RESET;
        return;
    }

    file << totalDonors << endl;

    for (int i = 0; i < totalDonors; i++) {

        file << donors[i].id << endl;
        file << donors[i].name << endl;
        file << donors[i].age << endl;
        file << donors[i].bloodGroup << endl;
        file << donors[i].phone << endl;
    }

    file.close();
}

void loadFromFile() {

    ifstream file("donors.txt");

    if (!file)
        return;

    file >> totalDonors;

    file.ignore();

    for (int i = 0; i < totalDonors; i++) {

        file >> donors[i].id;
        file.ignore();

        getline(file, donors[i].name);

        file >> donors[i].age;
        file >> donors[i].bloodGroup;
        file >> donors[i].phone;

        file.ignore();

        if (donors[i].id >= nextID)
            nextID = donors[i].id + 1;
    }

    file.close();
}

void countDonors() {
    cout << BLUE << "\nTotal Donors: " << RESET << totalDonors << endl;
}

int main() {

    enableColors();

    loadFromFile();

    int choice;

    do {
        cout << CYAN << "\n=============================\n" << RESET;
        cout << BOLD << RED << " BLOOD BANK MANAGEMENT SYSTEM\n" << RESET;
        cout << CYAN << "=============================\n" << RESET;
        cout << GREEN << "1. Add Donor\n" << RESET;
        cout << GREEN << "2. View Donors\n" << RESET;
        cout << GREEN << "3. Search by Blood Group\n" << RESET;
        cout << GREEN << "4. Search by Name\n" << RESET;
        cout << GREEN << "5. Blood Group Statistics\n" << RESET;
        cout << GREEN << "6. Count Donors\n" << RESET;
        cout << GREEN << "7. Delete Donor\n" << RESET;
        cout << GREEN << "8. Update Donor\n" << RESET;
        cout << GREEN << "9. Exit\n" << RESET;
        cout << YELLOW << "Enter Choice: " << RESET;
        cin >> choice;

        switch (choice) {

        case 1:
            addDonor();
            break;

        case 2:
            viewDonors();
            break;

        case 3:
            searchBloodGroup();
            break;

        case 4:
            searchByName();
            break;

        case 5:
            bloodGroupStatistics();
            break;

        case 6:
            countDonors();
            break;

        case 7:
            deleteDonor();
            break;

        case 8:
            updateDonor();
            break;

        case 9:
            saveToFile();

            cout << GREEN << "\nData saved successfully!\n" << RESET;
            cout << CYAN << BOLD << "\nThank you for using the Blood Bank Management System!\n" << RESET;
            break;

        default:
            cout << RED << "\nInvalid choice!\n" << RESET;
        }
    } while (choice != 9);

    return 0;
}
