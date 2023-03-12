Summary:
    1. Application
        This application allows the user to manage DVDs in a store. It reads DVDs data from files, makes changes, and saves the result back to the file or a new file depending on the file name we give. It enables users to search, check in, check out, check availability, monitor the current stock and details of DVDs, change DVD info, add or remove DVDs and would print out instructions or error info to help with the operation.
    2. Structure
        1.DVD class: DVD.cpp/DVD.h
        2.DVDstore class: DVDstore.cpp/DVDstore.h
        3.The application the user use: main.cpp
        4.DVDstore.txt: we read data from this file
        5.DVDresult.txt: we write data to this file
        
        The application reads data from file 1 and writes data to file 2 because this makes the change clear when testing. Please change the file name in "outFile.open("")" if you want to make changes to the original file. It's also the purpose of my application that the file represents the database so it's better to have only one file to work on.
        Run main.cpp
    3.File Format
        Number of DVDs in the store   // line1
        -----line beween------    // line2
        Title   // line3
        Number of stars
        Star1
        Star2
        ..
        Producer
        Director
        Procompany
        Copies
        -----line beween------
        Title
        ...
        ...
        -----line beween------

Algorithm:
    1. I choose map as the database to store different DVDs because I want the search to be efficient instead of using a for loop to look for a DVD with certain title. Check-in, Check-out, Check availability, show info on a DVD and other functions are all based on searching a DVD object by title from the database.
    2. I create one more class, which is DVDstore. Because if we group those typical methods into a class, we can reuse the whole block of codes, and make our main.cpp clean and clear and makes it easier to manage multiple stores instead of only one store by creating objects.
    3. We read the DVDs data from file, make some changes and can save the changed result back to the file.

Assumption:
    1. Assume one DVD can only have up to 4 stars.
    2. We consider two DVDs are the same if they have the same name and the only way to update info of DVD is using update() instead of using Add() to add a DVD with the same name again.
    3. We cannot check in a DVD that is not in the store, checkIn() is only for returning a DVD that has been borrowed before.
    4. UpdateDVD() has two conditions:
        a. When the user wants to update/change every piece of information on a DVD, the system will remove the old one from store's database and instruct user to add a new DVD with brand-new information.
        b. When a user wants to update only part of the information of a DVD, the user may change every unit one by one following the instruction.
    5. AddDVD()
      add method will allow users to add multiple DVDs at one time, which means the system will first instruct the user to enter how many DVDs the user wants to add at this time, and then allow the user to enter information for each DVD one by one.

Limitation:
    1. The number of stars is limited to 4 and the number of producer, proCompany, director is limited to 1.
    2. If we want to add an existing DVD, it doesn’t print any error info but just receive info and throw it.
    3. We cannot have different DVD with the same name, for example, we should use a list to store all these different DVDs with the same name and optimize the search Algorithm.
    4. We cannot enter string/char instead of integer for “number of stars” or “number of DVD you want to add”. The program doesn’t set up related screening process for valid input, will crash if use doesn’t follow the instruction.