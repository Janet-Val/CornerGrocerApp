"# CornerGrocerApp" 
"# CornerGrocerApp" 
* Summarize the project and what problem it was solving?
  The project required I create a program that tracked daily grocery item inventory. It kept a record of all items in chronological order, displayed their frequencies in numeric and histogram form, and backed up the data in a new file.

* What did you do particularly well?
  I think what I did particularly well was by implementing object-oriented programming. I encapsulated the data traits for the grocery items and their variables into a class. Then in the main method I called on the methods defined in the class.
  
* Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
  I can enhance my code by adding a case conversion function. This would allow the code to read the user input regardless of capitalization and make it user friendly.
  
* Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  The piece of code that I found the most challenging was reading the input file without causing an infinite loop. I needed to ensure that the text file was read with the loop’s conditional statements until the end of the file. This function, !inFile.eof(), would cause a logic error because it would try to return true after the end of file instead of when it reached a value that met the conditional statements. This would then cause an infinite loop. To get around this I used the function, inFile >> name, instead because it would execute the loop only if the value was true.  Visual studio debugger is already an important tool in my support network but another one I will utilize is the C++ reference website. Especially when needed to remember certain algorithms it is a great tool to reference.

* What skills from this project will be particularly transferable to other projects or course work?
  The skills I think will be particularly transferable to other projects or course work are using maps and pointers. Maps are good when you need to associate a unique key to a specific value and this is best used for lists or counting quantities. Then pointers allow you to access these exact objects that are stored on the map. Another transferrable skill is input and output streams. This will help when needing to read an already existing file or create a new file.

* How did you make this program maintainable, readable, and adapatable?
  This program was maintainable, readable, and adaptable because of the use of object-oriented programming. Separating the item data and logic into a class prevented the main function from becoming congested. Also using a maps with pointers and iterators, provides an efficient way to store, reference, and loop through data safely and minimizes logic errors.
