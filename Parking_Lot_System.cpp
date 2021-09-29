#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class parking
{
   string nm, num_plate, final_vehicle;
   int ph, vehicle_type, choice;
   int park_ch = 0, wash_type, car_wash, current_t;
   int memid, memid1, car_ch, total_charge = 0, memship_ch;
   int entry_time, exit_time, total = 0, charge;
   float tot_money = 0.0;
   long int tot_vehicles = 0, c_tot_vehicles = 0;

public:
   void login()
   {
      int c;
      system("cls");
      cout << "\t ---PARKING SYSTEM--- \t" << endl;
      cout << "Welcome to Parking Lot Registration\n";
      cout << "1.Admin Page\n2.Register Vehicle for Parking\n3.Exit\n";
      cin >> c;
      switch (c)
      {
      case 1:
      {
         admin();
      }
      case 2:
      {
         get_data();
         parking_charge();
         carwash_charge();
         display();
      }
      case 3:
      {
         exit(0);
      }
      default:
      {
         cout << "Enter Valid Choice!!!";
         login();
      }
      }
   }
   void admin()
   {
      system("cls");
      int v;
      cout << "Total Vehicles = " << tot_vehicles << endl;
      cout << "Vehicles Currently in Lot = " << c_tot_vehicles << endl;
      cout << "Total Money Earned = Rs. " << tot_money << endl;
      cout << "Press:\n1.Reset Collection\n2.Remove Vehicle\n3.Go to Login Page\n";
      cin >> v;
      switch (v)
      {
      case 1:
      {
         system("cls");
         tot_money *= 0.0;
         tot_vehicles *= 0;
         login();
      }
      case 2:
      {
         c_tot_vehicles--;
         login();
      }
      case 3:
      {
         login();
      }
      default:
      {
         cout << "Enter Valid Choice!!!";
         login();
      }
      }
   }
   void get_data()
   {
      system("cls");
      cout << "\nEnter Name: ";
      cin >> nm;
      cout << "\nEnter Vehicle Number: ";
      cin >> num_plate;
   a:
      cout << "\nEnter the Vehicle Type: " << endl;
      cout << "1. Two Wheeler " << endl;
      cout << "2. Hatch Back/Sedan " << endl;
      cout << "3. SUV/Van/Jeep " << endl;
      cout << "4. Heavy Vehicle " << endl
           << endl;
      cout << "Choice: ";
      cin >> vehicle_type;
      switch (vehicle_type)
      {
      case 1:
         cout << "Vehicle Type: Two Wheeler";
         break;
      case 2:
         cout << "Vehicle Type: Hatch Back/Sedan";
         break;
      case 3:
         cout << "Vehicle Type: SUV/Van/Jeep";
         break;
      case 4:
         cout << "Vehicle Type: Heavy Vehicle";
         break;
      default:
         cout << " ---INVALID INPUT !--- ";
         goto a;
         break;
      }

      cout << "\nEnter the current time in 24 hr format (Example: 1630):";
      cin >> current_t;

   z:
      cout << "\nDo you want us to do the Car Wash:" << endl;
      cout << "1. Yes " << endl;
      cout << "2. No " << endl;
      cin >> car_wash;
      switch (car_wash)
      {
      case 1:
      {
         cout << "Which one of the following would you like: " << endl;
         cout << "1. Only Exterior- Rs.200 " << endl;
         cout << "2. Interior Detailing- Rs.750 " << endl;
         cout << "3. Car Spa- Rs.850 " << endl;
         cin >> wash_type;
         break;
      }

      case 2:
      {
         cout << "\nThen we may proceed with generating the INVOICE!! " << endl;
         break;
      }
      default:
         cout << "\n ---INVALID INPUT !--- ";
         goto z;
      }
   }

   void parking_charge()
   {
      if (vehicle_type == 1 && current_t >= 0 && current_t <= 1200)
      {
         tot_vehicles++;
         c_tot_vehicles++;
         tot_money += 40;
         final_vehicle = "Two Wheeler";
         park_ch = 40;
         total_charge = 40;
      }
      else if (vehicle_type == 1 && current_t > 1200 && current_t <= 2400)
      {
         tot_vehicles++;
         c_tot_vehicles++;
         tot_money += 70;
         final_vehicle = "Two Wheeler";
         park_ch = 70;
         total_charge = 70;
      }
      else if (vehicle_type == 2 && current_t > 0 && current_t <= 1200)
      {
         tot_vehicles++;
         c_tot_vehicles++;
         tot_money += 50;
         final_vehicle = "Hatch Back/Sedan";
         park_ch = 50;
         total_charge = 50;
      }
      else if (vehicle_type == 2 && current_t > 1200 && current_t <= 2400)
      {
         tot_vehicles++;
         c_tot_vehicles++;
         tot_money += 80;
         final_vehicle = "Hatch Back/Sedan";
         park_ch = 80;
         total_charge = 80;
      }
      else if (vehicle_type == 3 && current_t > 0 && current_t <= 1200)
      {
         tot_vehicles++;
         c_tot_vehicles++;
         tot_money += 60;
         final_vehicle = "SUV/Van/Jeep";
         park_ch = 60;
         total_charge = 60;
      }
      else if (vehicle_type == 3 && current_t > 1200 && current_t <= 2400)
      {
         tot_vehicles++;
         c_tot_vehicles++;
         tot_money += 90;
         final_vehicle = "SUV/Van/Jeep";
         park_ch = 90;
         total_charge = 90;
      }
      else if (vehicle_type == 4 && current_t > 0 && current_t <= 1200)
      {
         tot_vehicles++;
         c_tot_vehicles++;
         tot_money += 100;
         final_vehicle = "Heavy Vehicle";
         park_ch = 100;
         total_charge = 100;
      }
      else if (vehicle_type == 4 && current_t > 1200 && current_t <= 2400)
      {
         tot_vehicles++;
         c_tot_vehicles++;
         tot_money += 130;
         final_vehicle = "Heavy Vehicle";
         park_ch = 130;
         total_charge = 130;
      }
   }
   void carwash_charge()
   {
      if (wash_type == 1)
      {
         car_ch = 200;
         total_charge += car_ch;
      }
      else if (wash_type == 2)
      {
         car_ch = 750;
         total_charge += car_ch;
      }
      else if (wash_type == 3)
      {
         car_ch = 850;
         total_charge += car_ch;
      }
   }
   void display()
   {
      system("cls");
      int v;
      time_t now = time(0);
      tm *ltm = localtime(&now);
      cout << "\n\t---Invoice---\t" << endl
           << endl;
      cout << "Date and Time    : " << ltm->tm_mday << "-" << 1 + ltm->tm_mon << "-" << 1900 + ltm->tm_year << "  " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
      cout << "Ticket Number	 : " << tot_vehicles << endl;
      cout << "Vehicle Type     : " << final_vehicle << endl;
      cout << "Vehicle number   : " << num_plate << endl;
      cout << "Parking Charges  : Rs." << park_ch << endl;
      cout << "Car Wash Charges : Rs." << car_ch << endl;
      cout << "Total Charge     : Rs." << total_charge << endl;
      cout << "Thank You for using our Parking Services !" << endl
           << endl;
   x:
      cout << "Press 1 to Go to Login or 0 to Exit\n";
      cin >> v;
      switch (v)
      {
      case 1:
      {
         login();
      }
      case 0:
      {
         exit(0);
      }
      default:
      {
         cout << "Enter Valid Choice!!!";
         goto x;
      }
      }
   }

} pk1;

int main()
{
   pk1.login();
   return 0;
}
