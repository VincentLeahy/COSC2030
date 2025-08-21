# Instructions  

Design a class called `NumDays`. The class’s purpose is to store a value that represents a number of work hours and convert it to a number of days. For example, 8 hours would be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would be converted to 2.25 days. The class should have a constructor that accepts a number of hours, as well as member functions for storing and retrieving the hours and days. The class should also have the following overloaded operators:

* ___Addition operator (+).___ When two `NumDays` objects are added together, the overloaded + operator should return the sum of the two objects’ hours members.
* ___Subtraction operator (-).___ When one `NumDays` object is subtracted from another, the overloaded - operator should return the difference of the two objects’ hours members.
* ___Prefix and postfix increment operators (++).___ These operators should increment the number of hours stored in the object. When incremented, the number of days should be automatically recalculated.
* ___Prefix and postfix decrement operators (--).___ These operators should decrement the number of hours stored in the object. When decremented, the number of days should be automatically recalculated.

Review [Solving the `NumDays` Class Problem](https://mediaplayer.pearsoncmg.com/assets/gaddis_cpp10e_1403_Solving_NumDays_Problem) VideoNote. You will see the output you should have for this programming challenge as well as the code. 