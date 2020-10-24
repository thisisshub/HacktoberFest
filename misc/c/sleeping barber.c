/*
the analogy is based upon a hypothetical barber shop with one barber.there is a barber shop which have one barber,
 one barber chair and n no of chairs for waiting for customers if there are any to sit on the chair.
- if there is no customer,then the barber sleeps in his own chair.
- when a customer arrives, he has to wake up the barber.
- if there are many customers and the barber is cutting customer hair, then the remaining customer either wait if 
   there are empty chairs in the waiting room or they leave if no chairs are empty.
   
   the solution to these problem includes three semaphor
   first is for customer which counts the no o f customer present in the  wiating room.
   2. the barber 0 or 1 is use to tell whether the barber is idel or working.
   and the third mutex is use to provid eyhe mutual exclusin whih is requre for the process to execute
   in the soltion the customer has the record the no of customer waiting in the waiting room if the no of the customer is 
   equal to the no of customer in the waiting room then the uocomming customer leaves the barber shop.
   when the barber shows early in the morning,he execute the procedure barber,causing him to block on the semaphore customers 
   because it is initially 0.
   then the barber goes to sleep.until the first customer comes up.
   when the customer arise he execute customer procedure tge customer aquries the mutex for entering the critical reion.
   if another customer arise there after,the second one will not be able to do any thing until the first one has release the mutex.
   the customer then checks the chairs in the waiting room.if waiting customer are less than the no. of chairs then he seats
   otherwise he leaves and releases the mutex.if the chairs is available in the waiting room and incriments the waiting value
   and also increses the customers semaphore which wakes up the barber if he is sleeping.
   at this point customer and barber are bith awake and the barber is ready to give that person an hearcut
   when the haircut is over the customer exit the proceduer if ther e are no customer in the waiting room barber sleeps
   
*/





