#include <iostream>
#include <string>
#include <queue>
using namespace std;

// ------------------- Patient information for respective department ---------------
class Patient {
    
public:
    static int no;
    string name;
    string info;
    int id;
    Patient* left = nullptr;
    Patient* right = nullptr;

    Patient(string name, string info) {
        no++;
        this->name = name;
        this->id = no;
        this->info = info;
    }

    void display() {
        cout << id << "  " << name << "  " << info << endl;
    }
};

int Patient::no = 0;

// -------------------- subdepartment that store patient list in that department -------------------

class SubDepartment {
    
public:
    string name;
    int subDeparmentNO;
    Patient* totalPatient = nullptr;

    SubDepartment* left = nullptr;
    SubDepartment* right = nullptr;

    SubDepartment(string name, int no) {
        this->name = name;
        this->subDeparmentNO = no;     
    }

   //Adding Patient in sub department used binary tree 
    
    void addPatient(string name, string info) {

        Patient* temp = new Patient(name, info);

        if (totalPatient == nullptr) {
            totalPatient = temp;
            return;
        }

        queue<Patient*> qe;
        qe.push(totalPatient);
        
        while (!qe.empty()) {

            Patient* demo = qe.front();
            qe.pop();
            if (demo->left == nullptr) {
                demo->left = temp;
                return;
            }
            else {
                qe.push(demo->left);
            }

            if (demo->right == nullptr) {
                demo->right = temp;
                return;
            }
            else {
                qe.push(demo->right);
            }
        }
    }

    //     display all the Patient in the list
    void display() {
        cout <<"---  " << subDeparmentNO << "  " << name << endl;
        if (totalPatient == nullptr) {
            cout << "No Patient in this Sub Department " << endl;
            return;
        }
        queue<Patient*> qe;
        qe.push(totalPatient);

        while (!qe.empty()) {

            Patient* demo = qe.front();
            qe.pop();
            if (demo->left != nullptr) {
                qe.push(demo->left);
            }

            if (demo->right != nullptr) {
                qe.push(demo->right);
            }

            demo->display();
        }
    }

    //       Remove Patient from respective department 
    void giveDischarge(int id) {

        if (totalPatient == nullptr) {
            cout << "No Patient in this Sub Department " << endl;
            return;
        }

        queue<Patient*> qe;
        qe.push(totalPatient);
        Patient* deepest = nullptr;
        Patient* parent = nullptr;
        Patient* oldPatient = nullptr;

        while (!qe.empty()) {
            Patient* demo = qe.front();
            qe.pop();
            if (demo->left != nullptr) {
                parent = demo;
                deepest = demo->left;
                qe.push(demo->left);
            }
            if (demo->right != nullptr) {
                parent = demo;
                deepest = demo->left;
                qe.push(demo->right);
            }

            if (demo->id == id) oldPatient = demo;
        }

        if (oldPatient != nullptr) {
            oldPatient->id = deepest->id;
            oldPatient->info = deepest->info;
            oldPatient->name = deepest->name;
            
            if (parent->left == deepest) {
                parent->left = nullptr;
                delete deepest;
            }
            else {
                parent->right = nullptr;
                delete deepest;
            }
        }
        else {
            cout << "Given id of Patient is Wrong" << endl;
        }
    }

    void removeAllSubDepartment() {
        if (totalPatient == nullptr) {
            return;
        }

        queue<Patient*> qe;
        Patient* demo = nullptr;
        qe.push(totalPatient);

        while (!qe.empty()) {

            demo = qe.front();
            qe.pop();
            if (demo->left != nullptr) {
                qe.push(demo->left);
            }


            if (demo->right == nullptr) {
                qe.push(demo->right);
            }
            delete demo;
        }
    }

 };



 //---------------------  Department class -------------------------
 class Department {

 public:
     string name;
     int id;
     SubDepartment* totalSubDepartment = nullptr;
     Department* left = nullptr;
     Department* right = nullptr;
     bool isThreaded = false;

     Department(string name, int no) {
         this->name = name;
         id = no;
     }

     void addSubDepartment(string name, int no){
         SubDepartment* temp = new SubDepartment(name, no);

         if (totalSubDepartment == nullptr) { totalSubDepartment = temp; return; }

         SubDepartment* child = totalSubDepartment;
         SubDepartment* parent = nullptr;

         while (child != nullptr) {
             if (child->subDeparmentNO > no) {
                 parent = child;
                 child = child->left;
             }
             else {
                 parent = child;
                 child = child->right;
             }

         }

         if (parent->subDeparmentNO > no) {
             parent->left = temp;
         }
         else {
             parent->right = temp;
         }

     }

     //      Display function to display all sub department in given department
     void displaySubDepartment(SubDepartment* node) {
         if (node == nullptr) {
             return;
         }
         else {
             displaySubDepartment(node->left);
  
             node->display();
             displaySubDepartment(node->right);
         }
     }

     //      Display function to display all sub department in given department
     void displaySubDepartmentById(int id) {

         if (totalSubDepartment == nullptr) {
             cout << "Given Deparment is empty" << endl;
             return;
         }
         else {
             SubDepartment* temp = totalSubDepartment;

             while (temp != nullptr) {
                 if (temp->subDeparmentNO == id) {
                     temp->display();
                     return;
                 }
                 else if (temp->subDeparmentNO > id) {
                     temp = temp->left;
                 }
                 else {
                     temp = temp->right;
                 }
             }

             cout << "Given Id is Not Found in the department" << endl;
         }
     }

     SubDepartment* removeSubDepartment(SubDepartment*& root, int id) {

         if (root == nullptr)return root;

         if (id < root->subDeparmentNO) {
             root->left = removeSubDepartment(root->left, id);
         }
         else if (id > root->subDeparmentNO) {
             root->right = removeSubDepartment(root->right, id);
         }
         else {

             if (root->left == nullptr && root->right == nullptr) {
                 delete root;
                 return root;
             }

             if (root->left == nullptr) {
                 SubDepartment* temp = root->right;
                 delete root;
                 return temp;
             }
             if (root->right == nullptr) {
                 SubDepartment* temp = root->left;
                 delete root;
                 return temp;
             }

             SubDepartment* temp = findMin(root->right); // Find the inorder successor
             root->subDeparmentNO = temp->subDeparmentNO; // Replace the value
             root->right = removeSubDepartment(root->right, temp->subDeparmentNO); // Delete successor

         }

         return root;
     }

     SubDepartment* findMin(SubDepartment* node) {
         if (node == nullptr) return nullptr;

         while (node->left != nullptr) {
             node = node->left;
         }

         return node;
     }

     // add patient in sub department
     void addPatient(int id, string name, string info) {

         if (totalSubDepartment == nullptr) return;

         SubDepartment* child = totalSubDepartment;

         while (child != nullptr) {
             if (child->subDeparmentNO == id) break;

             if (child->subDeparmentNO > id) {
                 child = child->left;
             }
             else {
                 child = child->right;
             }
         }
         if (child != nullptr) {
             child->addPatient(name, info);
         }
         else {
             cout << "Sub Deparment is Not Present" << endl;
         }
     }

     void removeDepartment() {
         SubDepartment* temp = totalSubDepartment;

         queue<SubDepartment*> qe;
         if (temp == nullptr) {
             return;
         }

         qe.push(temp);
         while (!qe.empty()) {
             SubDepartment* temp2 = qe.front();
             qe.pop();
             if (temp2->left != nullptr) {
                 qe.push(temp2->left);
             }
             if (temp2->right != nullptr) {
                 qe.push(temp2->right);
             }

             temp2->removeAllSubDepartment();
             delete temp2;
         }
     }
 };

 // ------------------------- Hospital -------------------------
 class Hospital {
 public: 
     string name;
     Department* allDeparment = nullptr;

     void addDeparment(string name, int no) {
         Department* newNode = new Department(name, no);

         if (allDeparment == nullptr) {
             allDeparment = newNode;
             return;
         }

         Department* current = allDeparment;
         Department* parent = nullptr;

         while (current != nullptr) {
             parent = current;

             if (no < current->id) {
                 if (current->left == nullptr) break;
                 current = current->left;
             }
             else {
                 if (current->right == nullptr || current->isThreaded) break;
                 current = current->right;
             }
         }


         if (no < parent->id) {
             parent->left = newNode;
             newNode->right = parent;
             newNode->isThreaded = true;
         }
         else {
             newNode->right = parent->right;
             newNode->isThreaded = parent->isThreaded;
             parent->right = newNode;
             parent->isThreaded = false;
         }
     }

     void display() {
         if (allDeparment == nullptr) {
             cout << "Tree is empty." << endl;
             return;
         }

         Department* current = allDeparment;

         while (current->left != nullptr) {
             current = current->left;
         }


         while (current != nullptr) {
             cout << "-----   " << current->id << " " << current->name<<endl;
             if (current->isThreaded) {
                 current = current->right;
             }
             else {

                 current = current->right;
                 while (current != nullptr && current->left != nullptr) {
                     current = current->left;
                 }
             }
         }
     }

     void displayWithPatient() {
         if (allDeparment == nullptr) {
             cout << "Tree is empty." << endl;
             return;
         }

         Department* current = allDeparment;

         while (current->left != nullptr) {
             current = current->left;
         }


         while (current != nullptr) {
             cout << current->id << " " << current->name << endl<<endl;
             current->displaySubDepartment(current->totalSubDepartment);
             if (current->isThreaded) {
                 current = current->right;
             }
             else {

                 current = current->right;
                 while (current != nullptr && current->left != nullptr) {
                     current = current->left;
                 }
             }
         }
     }

     void addSubDepartment(int no, string name, int id) {
         if (allDeparment == nullptr) {
             cout << "Tree is empty." << endl;
             return;
         }

         Department* current = allDeparment;

         while (current->left != nullptr) {
             current = current->left;
         }

         while (current != nullptr) {
             if (current->id == no)break;
             if (current->isThreaded) {
                 current = current->right;
             }
             else {

                 current = current->right;
                 while (current != nullptr && current->left != nullptr) {
                     current = current->left;
                 }
             }
         }

         current->addSubDepartment(name, id);
     }

     void addPatient(int no, int no2, string name, string info) {
         if (allDeparment == nullptr) {
             cout << "Tree is empty." << endl;
             return;
         }

         Department* current = allDeparment;

         while (current->left != nullptr) {
             current = current->left;
         }

         while (current != nullptr) {
             if (current->id == no)break;
             if (current->isThreaded) {
                 current = current->right;
             }
             else {

                 current = current->right;
                 while (current != nullptr && current->left != nullptr) {
                     current = current->left;
                 }
             }
         }

         current->addPatient(no2, name, info);
     }

     void removeDepartment(int no) {
         if (allDeparment == nullptr) {
             cout << "Tree is empty." << endl;
             return;
         }

         Department* current = allDeparment;

         while (current->left != nullptr) {
             current = current->left;
         }

         while (current != nullptr) {
             if (current->id == no) {
                 current->removeDepartment();
                 delete current;
                 break;
             }
         }
     }
     void removeSubDepartment(int no, int id) {
         if (allDeparment == nullptr) {
             cout << "Tree is empty." << endl;
             return;
         }

         Department* current = allDeparment;

         // Find the department with ID 'no'
         while (current != nullptr) {
             if (current->id == no) break;

             if (current->isThreaded) {
                 current = current->right;
             }
             else {
                 current = current->right;
                 while (current != nullptr && current->left != nullptr) {
                     current = current->left;
                 }
             }
         }

         if (current == nullptr) {
             cout << "Department with ID " << no << " not found." << endl;
             return;
         }

         // Remove the SubDepartment with ID 'id'
         current->totalSubDepartment = current->removeSubDepartment(current->totalSubDepartment, id);
     }


 };

int main()
{
    std::cout << "--------------- Hospital Management System -------------------"<<endl<<endl;

    Hospital hp;
    hp.addDeparment("Cardiology", 102);
    hp.addDeparment("Surgery", 113);
    hp.addDeparment("Neurology", 104);
    hp.addDeparment("Urology", 125);
 /*   hp.display();*/
    cout << endl << endl;
    hp.addSubDepartment(102, "Interventional Cardiology", 6);
    hp.addSubDepartment(102, "Electrophysiology", 8);
    hp.addSubDepartment(102, "Pediatric Cardiology", 5);
    //hp.displayWithPatient();

    hp.addPatient(102, 5, "sachin", "sadasdassd");
    hp.addPatient(102, 5, "Ram", "sadasdassd");
    //hp.removeSubDepartment(102, 6);
    hp.displayWithPatient();
     

    Department dp("Cardiology", 102);
    dp.addSubDepartment("Interventional Cardiology", 6);
    dp.addSubDepartment("Electrophysiology", 8);
    dp.addSubDepartment("Pediatric Cardiology", 5);
    dp.removeSubDepartment(dp.totalSubDepartment, 6);
    dp.displaySubDepartment(dp.totalSubDepartment);

}
