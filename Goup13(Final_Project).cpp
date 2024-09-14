#include <iostream>
#include <string>
#include <map>
#include <limits>

void login();
void admin_login();
void user_login();
void admin_interface();
void user_interface();
void search_book_by_id();
void borrow_book();
void transaction();
void services();
void return_book();
void olselectionbook();
void submain();

using namespace std;

struct Book {
    string name;
    string author;
    int price;
    Book() : price(0) {} // Initialize price to 0
};

class Library {
private:
    map<string, Book> books;
    map<string, int> bookPrices;
    map<string, string> adminLogins;
    map<string, string> userLogins;

public:
    Library() {
        // Initialize the class member variables
        this->books = map<string, Book>();
        this->bookPrices = map<string, int>();

        // Setting admin and user logins
        adminLogins["admin"] = "password"; // Replace with your desired admin username and password
        userLogins["user"] = "password"; // Replace with your desired user username and password

        // Adding available books
        Book book;
        book.name = "How to Program";
        book.author = "Philip Joe";
        book.price = 200;
        books["K001"] = book;

        book.name = "Learning Psychology (3rd edition)";
        book.author = "Rodney, Gary V.";
        book.price = 150;
        books["K002"] = book;

        book.name = "Approach to Early Childhood Education";
        book.author = "Gordonworth";
        book.price = 180;
        books["K003"] = book;

        book.name = "Math Methods and Techniques";
        book.author = "Einsberg, Harley G.";
        book.price = 220;
        books["K004"] = book;

        book.name = "Roots of English Learning";
        book.author = "Harry Saver";
        book.price = 170;
        books["K005"] = book;

        // Adding book prices
        bookPrices["K001"] = 200;
        bookPrices["K002"] = 150;
        bookPrices["K003"] = 180;
        bookPrices["K004"] = 220;
        bookPrices["K005"] = 170;
    }

    //Test if admin username and password is correct
    bool adminLogin(string username, string password) {
        if (adminLogins.find(username) != adminLogins.end() && adminLogins[username] == password) {
            return true;
        }
        return false;
    }

    //Test if user username and password is correct
    bool userLogin(string username, string password) {
        if (userLogins.find(username) != userLogins.end() && userLogins[username] == password) {
            return true;
        }
        return false;
    }

    //Test if the bookid is valid
    bool isValidBookId(string bookId) {
        system("cls");
        cout << "\t=============================================================================================================================" << endl;
        cout << "\t                                                     HERE'S THE DETAILS                                                        " << endl;
        cout << "\t=============================================================================================================================\n" << endl;
        Book book = books[bookId];
        cout << "\t\tBook ID: " << bookId << endl;
        cout << "\t\tName: " << book.name << endl;
        cout << "\t\tAuthor: " << book.author << endl;
        cout << "\t\tPrice: $" << bookPrices[bookId] << endl;
        return books.find(bookId) != books.end();
    }

    //Display book details
    void displayBookDetails(string bookId) {
        system("cls");
        Book book = books[bookId];
        cout << "\t\tBook ID: " << bookId << endl;
        cout << "\t\tName: " << book.name << endl;
        cout << "\t\tAuthor: " << book.author << endl;
        cout << "\t\tPrice: $" << bookPrices[bookId] << endl;
    }

    //Function to add book
    void addBook(string bookId, string bookName, string bookAuthor, int bookPrice) {
        Book book;
        book.name = bookName;
        book.author = bookAuthor;
        book.price = bookPrice;
        books[bookId] = book;
        bookPrices[bookId] = bookPrice;
    }

    //Function to deletebook
    void deleteBook(string bookId) {
        books.erase(bookId);
        bookPrices.erase(bookId);
    }

    //Function to updatebook
    void updateBook(string bookId, string bookName, string bookAuthor, int bookPrice) {
        if (books.find(bookId) != books.end()) {
            books[bookId].name = bookName;
            books[bookId].author = bookAuthor;
            bookPrices[bookId] = bookPrice;
        }
    }

    //Function to updatebook
    void displayAllBooks() {
        system("cls");
        cout << "\t=============================================================================================================================" << endl;
        cout << "\t                                                     AVAILABLE BOOKS                                                       " << endl;
        cout << "\t=============================================================================================================================\n" << endl;
        
        for (const auto& book : books) {
            cout << "\t\tBook ID: " << book.first << endl;
            cout << "\t\tName: " << book.second.name << endl;
            cout << "\t\tAuthor: " << book.second.author << endl;

            if (bookPrices.find(book.first) != bookPrices.end()) {
                cout << "\t\tPrice: $" << bookPrices[book.first] << endl;
            }
            else {
                cout << "\t\tPrice: N/A" << endl; // Kung walang presyo sa bookPrices
            }

            cout << "\t----------------------------------------------------------------------------------------------------------------------------\n" << endl;
        }
    }
};


Library library;
string logged_in_username;

//function to login
void login() {
    system("cls");
    int c;
    string username, password;
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t                                                  WELCOME TO LOGIN PAGE                                                        " << endl;
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t=============================================================================================================================\n" << endl;
    cout << "\t\t1. Login as User" << endl;
    cout << "\t\t2. Login as Admin" << endl;
    cout << "\t\t3. Go back to the main menu" << endl;
    cout << "\t\t     Please choose...";
    
    cin >> c;


    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (c) {
    case 1:
        user_login();
        break;
    case 2:
        admin_login();
        break;
    case 3:
        break;
        login();
    default:
        cout << "\t\t\tInvalid choice. Please try again.\n";
        break;
    }
}
struct Appointment {
    // Create a new appointment node
    string name;
    int age=0;
    string year;
    string course;
    string srCode;
    string address;
    Appointment* next = nullptr;
};

// Function to add a new appointment to the linked list
void addAppointment(Appointment** head) {
    system("cls");
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t                                                     APPOINTMENT SLIP                                                        " << endl;
    cout << "\t=============================================================================================================================\n" << endl;
    // Create a new appointment node
    Appointment* newAppointment = new Appointment;

    // Ask for appointment details
    cout << "\tEnter name: ";
    cin.ignore();
    getline(cin, newAppointment->name);
    cout << "\tEnter age: ";
    cin >> newAppointment->age;
    cout << "\tEnter year: ";
    cin.ignore();
    getline(cin, newAppointment->year);
    cout << "\tEnter course: ";
    getline(cin, newAppointment->course);
    cout << "\tEnter SR code: ";
    getline(cin, newAppointment->srCode);
    cout << "\tEnter address: ";
    getline(cin, newAppointment->address);

    // Set next pointer of the new appointment
    newAppointment->next = nullptr;

    // If the linked list is empty, make the new appointment as the head
    if (*head == nullptr) {
        *head = newAppointment;
    }
    else {
        // Traverse to the end of the linked list
        Appointment* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

    }
}

// Function to display all appointments in the linked list
void displayAppointments(Appointment* head) {
    if (head == nullptr) {
        cout << "No appointments found." << endl;
    }
    else {
        system("cls");
        cout << "\t=============================================================================================================================" << endl;
        cout << "\t                                                     APPOINTMENT SLIP                                                       " << endl;
        cout << "\t=============================================================================================================================\n" << endl;
        Appointment* temp = head;
        while (temp != nullptr) {
            cout << "\n\t\tName: " << temp->name << endl;
            cout << "\t\tAge: " << temp->age << endl;
            cout << "\t\tYear: " << temp->year << endl;
            cout << "\t\tCourse: " << temp->course << endl;
            cout << "\t\tSR code: " << temp->srCode << endl;
            cout << "\t\tAddress: " << temp->address << endl;
            temp = temp->next;
        }
    }
}

// Function to login the admin
void admin_login() {
    system("cls");
    string username, password;
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t                                                      ADMIN LOGIN PAGE                                                        " << endl;
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t=============================================================================================================================\n" << endl;
    cout << "\t\033[1m\033[32m\033[5mPlease Login\033[0m\n" << endl;
    cout << "\t\t\033[3mLogin using your credentials.\033[0m\n" << endl;

    cout << "\t\t\tEnter your username: ";
    getline(cin, username);
    cout << "\t\t\tEnter your password: ";
    getline(cin, password);

    if (library.adminLogin(username, password)) {
        logged_in_username = username;
        admin_interface();
    }
    else {
        cout << "\t\t\tInvalid credentials. Please try again.\n";
        login();
    }
}

// Function to login the user
void user_login() {
    system("cls");
    string username, password;
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t                                                     USER LOGIN PAGE                                                        " << endl;
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t=============================================================================================================================\n" << endl;
    cout << "\t\033[1m\033[32m\033[5mPlease Login\033[0m\n" << endl;
    cout << "\t\t\033[3mLogin using your credentials.\033[0m\n" << endl;

    cout << "\t\t\tEnter your username: ";
    getline(cin, username);
    cout << "\t\t\tEnter your password: ";
    getline(cin, password);

    if (library.userLogin(username, password)) {
        logged_in_username = username;
        user_interface();
    }
    else {
        cout << "\t\t\tInvalid credentials. Please try again.\n";
        login();
    }
}

// Function for admin interface
void admin_interface() {
    system("cls");
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t                                                     ADMIN INTERFACE                                                        " << endl;
    cout << "\t=============================================================================================================================\n" << endl;
    int choice;
    cout << "\t\t1. Display all books" << endl;
    cout << "\t\t2. Add" << endl;
    cout << "\t\t3. Update Book" << endl;
    cout << "\t\t4. Delete a book" << endl;
    cout << "\t\t5. Search a Book" << endl;
    cout << "\t\t6. Logout" << endl;
    cout << "\t\t\tEnter your choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string bookId, bookName, bookAuthor;
    int bookPrice;

    if (choice == 1) {
        library.displayAllBooks();

        cout << "\t\t\tPress any key to return....";
        int key= getchar(); // Wait for user input
        admin_interface();
    }
    else if (choice == 2) {
        system("cls");
        cout << "\t=============================================================================================================================" << endl;
        cout << "\t                                                        ADD BOOK                                                        " << endl;
        cout << "\t=============================================================================================================================\n" << endl;
        
        cout << "\n\t\tEnter details to add a new book." << endl;
        cout << "\n\t\tEnter the book name: ";
        getline(cin, bookName);

        cout << "\t\tEnter the book author: ";
        getline(cin, bookAuthor);

        cout << "\t\tEnter the book price: ";
        cin >> bookPrice;
        cout << "\t\tEnter the book Id: ";
        getline(cin, bookId);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        library.addBook(bookId, bookName, bookAuthor, bookPrice);
        cout << "\n\t\t\tBook added successfully!" << endl;

        cout << "\n\t\t\tPress any key to return...";
        int key= getchar(); // Wait for user input
        admin_interface();
    }
    else if (choice == 3) {
        system("cls");

        library.displayAllBooks();

        cout << "\n\tEnter the book ID that you want to update: ";
        getline(cin, bookId);

        if (library.isValidBookId(bookId)) {
            cout << "\n\t\tBook found. Enter new book details to update .\n" << endl;
            cout << "\t\tEnter new book name: ";
            getline(cin, bookName);

            cout << "\t\tEnter new book author: ";
            getline(cin, bookAuthor);

            cout << "\t\tEnter the book Id: ";
            getline(cin, bookId);

            cout << "\t\tEnter new book price: ";
            cin >> bookPrice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            library.updateBook(bookId, bookName, bookAuthor, bookPrice);
            cout << "\n\n\t\t\tBook updated successfully!" << endl;
        }
        else {
            cout << "\n\t\t\tBook not found. Please try again!!" << endl;
            return;
        }
        cout << "\n\t\t\tPress any key to return...";
        int key = getchar(); // Wait for user input
        admin_interface();
    }
    else if (choice == 4) {
        system("cls");

        library.displayAllBooks();

        cout << "\tEnter the book ID of the book that you want to delete. ";
        getline(cin, bookId);

        if (library.isValidBookId(bookId)) {
            cout << "\t\tBook found. Enter new details to update .\n" << endl;
           
            cout << "\n\t\t\tBook Deleted successfully!" << endl;
        }
        else {
            cout << "\n\t\t\tBook not found. Please try again!!" << endl;
            return;
        }
        cout << "\t\t\tPress any key to return...";
        int key = getchar(); // Wait for user input
        admin_interface();
    }
    else if (choice == 5) {
        search_book_by_id();
        cout << "\t\t\tPress any key to return...";
        int key = getchar(); // Wait for user input

        // Clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Return to the admin interface
        admin_interface();
 
    }
    else if (choice == 6) {
        system("cls");
        cout << "\n\n\n\n\n\t\t\tLogged out successfully.\n\n\n\n\n\n";
        logged_in_username = "";
    }
    else {
        cout << "\t\t\tInvalid choice. Please try again.\n";
        admin_interface();
    }
}

// Function for user interface
void user_interface() {
    system("cls");
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t                                                     USER INTERFACE                                                        " << endl;
    cout << "\t=============================================================================================================================\n" << endl;
  
    int m;
    cout << "\t\t1. Make transaction" << endl;
    cout << "\t\t2. View other services" << endl;
    cout << "\t\t3. Exit" << endl;

    cout << "\t\t\tEnter your choice: ";
    cin >> m;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (m) {
    case 1:
        transaction();
        break;
    case 2:
        services();
        break;
    case 3:
        cout << "\n\t\tLogged out successfully.\n";
        logged_in_username = "";
        login();
        break;
    default:
        cout << "\n\t\tInvalid choice. Please try again.\n";
        user_interface();
        break;
    }
}

// Function to services that are availble to the library
void services() {
    system("cls");
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t                                                     SERVICES                                                        " << endl;
    cout << "\t=============================================================================================================================\n" << endl;
    cout << "\t\tServices that we offer.\n\n" << endl;
    cout << "\t\t1. Current Awareness Service " << endl;
    cout << "\t\t2. User Education " << endl;
    cout << "\t\t3. Research Assistance Service" << endl;
    cout << "\t\t4. Virtual Reference Assistance" << endl;
    cout << "\t\t5. Library Website and Social Media" << endl;
    cout << "\t\t6. Plagiarism Checking." << endl;
    cout << "\t\t7. Bibliographical Services.\n\n" << endl;

    cout << "\t\t\t\tPress any key to return...";
    int key = getchar(); // Wait for user input

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Return to the user interface
    user_interface();

}

// Function to make transaction
void transaction() {
    system("cls");
    int choice;
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t                                                     TRANSACTION                                                        " << endl;
    cout << "\t=============================================================================================================================\n" << endl;
    cout << "\n\tThese are the available transaction." << endl;
    cout << "\t\t1. Display all books" << endl;
    cout << "\t\t2. Search for a book by ID" << endl;
    cout << "\t\t3. Borrow a book" << endl;
    cout << "\t\t4. Return a book" << endl;
    cout << "\t\t5. Online book Selection" << endl;
    cout << "\t\t6. Onine Appointment" << endl;
    cout << "\t\t7. Logout" << endl;

    cout << "\t\t\tEnter your choice: ";
    cin >> choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 1) {
        library.displayAllBooks();
        cout << " \n\tPress any key to return...";
        int key = getchar(); // Wait for user input

        // Return to the user interface
        transaction();
    }
    else if (choice == 2) {
        search_book_by_id();
        cout << "\t\t\tPress any key to return...";
        int key = getchar(); // Wait for user input

        // Clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Return to the user interface
        transaction();
    }
    else if (choice == 3) {
        borrow_book();
    }
    else if (choice == 4) {
        return_book();
    }
    else if (choice == 5) {
        olselectionbook();
    }
    else if (choice == 6) {
        Appointment* appointments = nullptr; // Linked list head pointer
        system("cls");
        cout << "\t=============================================================================================================================" << endl;
        cout << "\t                                                ONLINE APPOINMENTS                                                        " << endl;
        cout << "\t=============================================================================================================================\n" << endl;
        
        char choice;
        do {
            cout << "\t=============================================================================================================================\n" << endl;
            cout << "\t1. Add an appointment";
            cout << "\t\t\t2. Display appointments";
            cout << "\t\t\t3. Exit"<<endl;
            cout << "\t=============================================================================================================================\n" << endl;

            cout << "\n\t\t\tEnter your choice: ";

            cin >> choice;

            switch (choice) {
            case '1':
                addAppointment(&appointments);
                break;
            case '2':
                displayAppointments(appointments);
                cout << "\n\t\t\tPresent this appointment slip to library staff." << endl;
                break;
            case '3':
                break;
            default:
                cout << "\n\n\t\t\nInvalid choice. Try again." << endl;
                break;
            }

            cout << endl;
        } while (choice != '3');

        // Free the memory allocated for appointments
        Appointment* current = appointments;
        while (current != nullptr) {
            Appointment* next = current->next;
            delete current;
            current = next;
        }

        return;
    }
    else if (choice == 7) {
        system("cls");
        cout << " \n\tLogged out successfully.\n";
        logged_in_username = "";
    }
    else {
        cout << " \n\tInvalid choice. Please try again.\n";
        user_interface();
    }  
}

// Function to return book
void return_book() {
    system("cls");
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t                                                     RETURN BOOK                                                        " << endl;
    cout << "\t=============================================================================================================================\n" << endl;
    // Add logic to handle returning a book
    cout << " \n\tEnter the book ID to return: ";
    string bookId;
    getline(cin, bookId);

    if (library.isValidBookId(bookId)) {
        // TODO: Implement the returning logic here
        cout << " \n\tBook returned successfully!\n";
    }
    else {
        cout << " \n\tBook ID not found. Please try again.\n";
    }

    cout << " \n\tPress any key to return...";
    int key = getchar(); // Wait for user input

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Return to transaction
    transaction();
}

// Function for online book selection
void olselectionbook() {
    system("cls");
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t                                                 SELECT BOOK ONLINE                                                        " << endl;
    cout << "\t=============================================================================================================================\n" << endl;
   
    library.displayAllBooks();

    // Add logic to handle purchasing a book
    cout << "Enter the book ID to select: ";
    string bookId;
    getline(cin, bookId);

    if (library.isValidBookId(bookId)) {

        // TODO: Implement the purchasing logic here
        cout << "\n\tBook was selected successfully!\n";
    }
    else {
        cout << "\n\tBook ID not found. Please try again...\n";
    }

    cout <<" \n\tPress any key to return...";
    int key = getchar(); // Wait for user input

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Return to the transaction page
    transaction();
}

// Function to search book using book id
void search_book_by_id() {
    system("cls");
    string bookId;
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t                                                     SEARCH BOOK                                                        " << endl;
    cout << "\t=============================================================================================================================\n" << endl;

    cout << "\t\tEnter the book ID: ";
    getline(cin, bookId);

    if (library.isValidBookId(bookId)) {
        cout << "\n\t\tBook Searched successfully!\n";
    }
    else {
        cout << "\n\t\tBook ID not found. Please try again.\n" << endl;
        search_book_by_id();
    }
   
}

// Function to borrow book
void borrow_book() {
    system("cls");
    cout << "\t=============================================================================================================================" << endl;
    cout << "\t                                                     BORROW BOOK                                                        " << endl;
    cout << "\t=============================================================================================================================\n" << endl;
    library.displayAllBooks();
    string bookId;
    cout << "\t\tEnter the book ID to borrow: ";
    getline(cin, bookId);

    if (library.isValidBookId(bookId)) {
        // TODO: Implement the borrowing logic here
        cout << "\n\t\tBook borrowed successfully!\n";
    }
    else {
        cout << "\t\tBook ID not found. Please try again.\n";
        borrow_book();
    }
    cout << "\t\t\tPress any key to return...";
    int key=getchar(); // Wait for user input

    // Return to the user interface
    transaction();
}

// Function to sub main page
void submain() {
    system("cls");
    int c;
    cout << "\t\t\t_________________________________________________________________________________" << endl;
    cout << "\t\t\t|\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t|\t\033[1;31mWelcome to Batangas State University - Lipa Campus Library System\033[0m\t| " << endl;
    cout << "\t\t\t|\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t|_______________________________________________________________________________|\n\n" << endl;
    cout << "\t\t\t_________________________________________________________________________________" << endl;
    cout << "\t\t\t| 1 LOGIN                               ||2 EXIT                                |" << endl;
    cout << "\t\t\t|_______________________________________________________________________________|\n\n" << endl;
    cout << "\n\t\t\t Please enter your choice: ";
    cin >> c;
    cout << endl;

    switch (c) {
    case 1:
        login();
        break;

    case 2:
        cout << "\n\n\t\t\tThank you! \n\n";
        break;

    default:
        cout << "\n\t\t\t please select from the given option \n" << endl;
        break;
    }
    return;
}

int main(){
    system("cls");
    cout << "\t****************************************************************************************************************************" << endl;
    cout << "\t*\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\t   *" << endl;
    cout << "\t*\t+\t\t\t\t\t\t\t\t\t\t\t\t          +\t   *" << endl;
    cout << "\t*\t+\t\t\t\t\tBATANGAS STATE UNIVERSITY\t\t\t\t          +\t   *" << endl;
    cout << "\t*\t+\t\t\t\t   \033[1;31mThe National Engineering University\033[0m\t\t\t                  +\t   * " << endl;
    cout << "\t*\t+\t\t\t\t\t\tLIPA CAMPUS\t\t\t\t\t\t   +\t   * " << endl;
    cout << "\t*\t+\t\t\t\t      \033[1;31mOFFICE OF THE LIBRARY SERVICES\033[0m\t\t\t\t\t   +\t   * " << endl;
    cout << "\t*\t+\t\t\t\t\t\t\t\t\t\t\t\t          +\t   *" << endl;
    cout << "\t*\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\t   *" << endl;
    cout << "\t****************************************************************************************************************************" << endl;
  
    cout << "\n\n\n\n\t\t\t\t\t\t\t        \033[34;47mFIND HERE!!\033[0m" << endl;

    cout << "\n\t\t\t\t\t\t\t  Press any key to continue....";
    int key = getchar(); // Wait for user input
    submain();
}