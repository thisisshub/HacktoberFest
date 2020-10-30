#Taking input balance from user
Balance=int(input("Please enter your account balance:"));
x=0
while x==0:   
#Making Menu    
            print("What do you want to do ? Please select a number:-");
            print(" 1)Withdraw\n 2)Deposit\n 3)None");
            Option=int(input());            
#To Withdraw money           
            if Option==1:
               print("Please enter the amount you want to withdraw:");
               Withdrawn_amount=int(input());
               if Withdrawn_amount<=Balance:
                 Balance=Balance-Withdrawn_amount;
                 print("Your new balance is",Balance);
               else:
                     print("You dont have the required money")
#To deposit money                     
            if Option==2:
                print("Please enter the amount you want to deposit:");
                Deposit_amount=int(input());
                Balance+=Deposit_amount;
                print("Your new balance is",Balance)
#To end program                
            if Option==3:
                print("Thank you for using this program");
                break
#For wrong input            
            if Option<1 or Option>3:
                print("Please try with the given numbers");
