## POS SYSTEM

This is a terminal-based POS System, equipped with features like `Auto-Complete`, `Employee Hierarchy`, `Random UUID Generation`, `Receipt Generation`, and much more!!

If anything seems off or bugs occur while running, please make an issue and I will address the problem as soon as possible

### Things To Know

Login must happen with the provided credentials
- Username: `spiderman` Password: `61064` Access Level: `cashier`
- Username: `thanos` Password: `43218` Access Level: `shiftlead`
- Username: `ligma` Password: `90236` Access Level: `managment`

Without using an external library there is no way to write into an `istream buffer`
This is relevant because when using the `Auto-Complete` features, you want to note
after every key is pressed and the generation of the search queue happens the previous
value you entered will be saved into the `ostream buffer` **NOT** the input buffer.

The `B` in this example is now not a deletable character
```
Search Queue
--------------
Buttermilk
Blue Cheese
Brown Flour
Barley
Butternut Lettuce
Bran
Beef Stock
Besan
Bok Choy
Banana
Borlotti Beans
Butternut Pumpkin

    Delete Item
----------------------
Enter Item Name: B
```

Receipts follow a strict format, if you manually enter a receipt be careful with formatting

For easy issue creation and readability, every exception thrown is a string.
This string thrown will always be caught before the program terminates, so expect a message

if any errors (of course besides any thrown by STL)

Finally enjoy

If you are browsing source code and wonder why I did something a
certain way, just know that I was experimenting a lot and purposely doing it
in certain ways to learn not to be efficient


### Build & Run

Step #1: `git clone https://github.com/Puwya/Sales-System.git`

Step #2: `cd Sales-System`

Step #3: `mkdir build && cd build`

Step #4: `cmake ..`

Step #5: `make`

Step #6: `./main`