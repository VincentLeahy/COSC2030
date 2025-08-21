# Instructions  

## Case Study: Sales Commission

Crazy Al’s Computer Emporium is a retail seller of home computers. The sales staff at Crazy Al’s works strictly on commission. At the end of the month, each salesperson’s commission is calculated according to Table 1. 

__Table 1. Commission Rates__
| Sales This Month | Commission Rate |
| ---------------- | --------------- |
| Less than $10,000 | 5% |
| $10,000 – $14,999 | 10% |
| $15,000 – $17,999 | 12% |
| $18,000 – $21,999 | 14% |
| $22,000 or more | 16% | 

For example, a salesperson with $16,000 in monthly sales will earn a 12 percent commission ($1,920.00). Another salesperson with $20,000 in monthly sales will earn a 14 percent commission ($2,800.00). 

Because the staff only gets paid once per month, Crazy Al’s allows each employee to take up to $1,500 per month in advance. When sales commissions are calculated, the amount of each employee’s advanced pay is subtracted from the commission. If any salesperson’s commissions are less than the amount of their advance, they must reimburse Crazy Al’s for the difference. 

Here are two examples: Beverly and John have $21,400 and $12,600 in sales, respectively. Beverly’s commission is $2,996 and John’s commission is $1,260. Both Beverly and John took $1,500 in advance pay. At the end of the month, Beverly gets a check for $1,496, but John must pay $240 back to Crazy Al’s. 

You’ve been asked to write a program that eases the task of calculating the end-of-month commission. Table 2 lists the variables needed.

__Table 2. Variables__
| Variable | Description |
| -------- | ----------- |
| `sales` | A double variable to hold a salesperson’s total monthly sales. |
| `rate` | A double variable to hold the salesperson’s commission rate. |
| `commission` | A double variable to hold the commission. |
| `advance` | A double variable to hold the amount of advanced pay the salesperson has drawn. |
| `pay` | A double variable to hold the salesperson’s amount of pay. |

### Program Design 

The program must perform the following general steps: 

1. Ask the user for the salesperson’s monthly sales. 
2. Ask the user for the amount of advance pay the salesperson has drawn from the company. 
3. Determine the commission rate. 
4. Calculate the commission. 
5. Calculate the salesperson’s pay by subtracting the advanced pay from the commission. If the amount is negative, the salesperson must reimburse the company.

### Determine the Commission Rate

The commission rate is determined by the monthly sales amount. An if/else if statement can be used to test the sales amount and assign the correct rate. 

The following pseudocode expresses the algorithm: 

	If sales is less than $10,000
		rate is 5%.
	else if sales is less than $15,000
		rate is 10%.
	else if sales is less than $18,000
		rate is 12%.
	else if sales is less than $22,000
		rate is 14%.
	else
		rate is 16%.

### The Program

Before attempting to code the problem, you should first model it entirely in pseudocode: 

	Ask user to enter the salesperson’s monthly sales. 
	Store input in sales. 
	Ask user to enter the salesperson’s amount of advanced pay. 
	Store input in advance. 
	If sales is less than $10,000 
		rate is 5%. 
	else if sales is less than $15,000 
		rate is 10%.
	else if sales is less than $18,000  
		rate is 12%. 
	else if sales is less than $22,000  
		rate is 14%. 
	else  
		rate is 16%. 
	commission = sales * rate. 
	pay = commission – advance. 
	Display results. 

The last step is to expand the pseudocode into the final program, which is shown below.

```C
// This program is used by Crazy Al's Computer Emporium 2  
// to calculate the monthly pay of commissioned sales people. 
 
 
#include <iostream> 
#include <iomanip> 

using namespace std;

int main()
{ 
 	double sales,       	// Monthly Sales
 	rate,        		// Rate of Commission
 	commission,  		// Amount of Commission
 	advance,     		// Advanced Pay Drawn
 	pay;         		// Pay remaining to be paid
 
	// Ask user for the salesperson's sales and the
	// amount of advanced pay.
	cout << "Enter the salesperson's monthly sales: ";
	cin >> sales;
	cout << "Enter the amount of advanced pay for this ";
	cout << "salesperson: ";
	cin >> advance;

	// Determine the commission rate.
	if (sales < 10000)
		rate = 0.05;
	else if (sales < 14999)
		rate = 0.1; 
	else if (sales < 17999)
		rate = 0.12;
	else if (sales < 21999)
		rate = 0.14;
	else
		rate = 0.16;

	 // Calculate the sales commission.
	 commission = sales * rate;

	 // Calculate the salesperson's pay.
	 pay = commission – advance;

	 // Display the results.
	 cout << fixed << showpoint << setprecision(2);
	 cout << "\nPay Results\n";
	 cout << "-----------\n";
	 cout << "Sales: $" << sales << endl;
	 cout << "Commission Rate: " << rate << endl;
	 cout << "Commission: $" << commission << endl;
	 cout << "Advanced Pay: $" << advance << endl;
	 cout << "Remaining Pay: $" << pay << endl;
	 return 0;
 }
 ```
 
 #### Program Output with Example Input Shown in Bold 
 
 Enter the salesperson's monthly sales: __19600__ [Enter]    
 Enter the amount of advanced pay for this salesperson: __1000__ [Enter]    
 
 `Pay Results`  
 `----------`
 `Sales: $19600.00` 
 `Commission Rate: 0.14`
 `Commission: $2744.00`
 `Advanced Pay: $1000.00`
 `Remaining Pay: $1744.00`
 
 #### Program Output with Different Example Input Shown in Bold 
 
 Enter the salesperson's monthly sales: __9000__ [Enter]    
 Enter the amount of advanced pay for this salesperson: __1000__ [Enter]    
     
 Pay Results    
 ----------    
 Sales: $9000.00     
 Commission Rate: 0.05     
 Commission: $450.00     
 Advanced Pay: $1000.00     
 Remaining Pay: $-550.00    