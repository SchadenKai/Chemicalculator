#include <iostream>
#include <string>
#include <cwchar>
#include <windows.h>
#include <conio.h>


using namespace std;
string history_reactant[10] = {"__", "__", "__", "__", "__", "__", "__", "__", "__", "__"};
string *history_reactantptr = &history_reactant[0];
string history_product[10] = {"__", "__", "__", "__", "__", "__", "__", "__", "__", "__"};
string *history_productptr = &history_product[0];
    string elements[10][20] ={
        {"H ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "He", " ", " "},// 1
        {"Li", "Be", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "B ", "C ", "N ", "O ", "F ", "Ne", " ", " "},// 2
        {"Na", "Mg", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "Al", "Si", "P ", "S ", "Cl", "Ar", " ", " "},// 3
        {"K ", "Ca", "Sc", "Ti", "V ", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", " ", ""},// 4
        {"Rb", "Sr", "Y ", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I ", "Xe", " ", ""},// 5
        {"Cs", "Ba", "  ", "Hf", "Ta", "W ", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", " ", ""},// 6
        {"Fr", "Ra", "  ", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og", " ", ""},// 7
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", " ", ""},// 8
        {"  ", "  ", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "  ", " ", ""},// 9
        {"  ", "  ", "Ac", "Th", "Pa", "U ", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "  ", " ", ""}// 10
        };
    double coefficient[6] = {0, 0, 0, 0, 0, 0};
    double *co_ptr = &coefficient[0];
    int indic1 = 0;
    int indic2 = 0;

    int no_reactant;
    int no_product;
    int no_iteration;
    int count_iteration;
    bool stop = false;
    char continues;
    int count_reactant;
    int count_product;
    int subscript_reactant[100] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int *subscript_reactantptr = &subscript_reactant[0];
    int subscript_product[100] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int *subscript_productptr = &subscript_product[0];
    int count;
    int no_sets_reactant;
    int no_sets_product;
    int no_reactant_1;
    int no_reactant_2;
    int no_product_1;
    int no_product_2;
    bool synthesis;
    bool decomposition;
    double var_1;
    double var_2;
    double n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
	double v1,v2,v3,v4,v5,v6,v7,v8,v9,v10;
	double t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;

void userinput1(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
    cout << "\t\tCHEMICALCULATOR " << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<< "How many Reactants will you Input?:	";
	cin>> no_sets_reactant;
	cout<<"How many Products will you input?:	";
	cin>> no_sets_product;
	cout << endl;

    if (no_sets_reactant == 2 && no_sets_product == 1){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "Chemical Reaction: Synthesis" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        synthesis = true;
        cout << "Number of elements in the first reactant: ";
        cin >> no_reactant_1;
        cout << "Number of elements in the second reactant: ";
        cin >> no_reactant_2;
        cout << "Number of elements in Product: ";
        cin >> no_product_1;
        no_iteration = no_reactant_1 + no_reactant_2 + no_product_1;
    }
    else if (no_sets_reactant == 1 && no_sets_product == 2){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "Chemical Reaction: Decompositiom " << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        decomposition = true;
        cout << "Number of element in Reactant: ";
        cin >> no_reactant_1;
        cout << "Number of element in first product: ";
        cin >> no_product_1;
        cout << "Number of element in second product: ";
        cin >> no_product_2;
        no_iteration = no_reactant_1 + no_product_1 + no_product_2;
    }
    else{
        cout << "Input not in the program. Please Try Again." << endl;
    }

}

void right_arrowkey(){
    indic2++;
        if(indic2 == 1 && indic1 == 0){
            indic2 = 17;
        }
        if(indic2 == 2 && indic1 == 1){
            indic2 = 12;
        }
        if(indic2 == 2 && indic1 == 2){
            indic2 = 12;
        }
        if(indic2 == 2 && indic1 == 5){
            indic2 = 3;
        }
        if(indic2 == 2 && indic1 == 6){
            indic2 = 3;
        }
        if(indic2 == 17 && indic1 == 8){
            indic2 = 2;
        }
        if(indic2 == 17 && indic1 == 9){
            indic2 = 2;
        }
        if(indic2 == 18){
            indic2 = 0;
        }
}
void left_arrowkey(){
    indic2--;
        if(indic2 == 16 && indic1 == 0){
            indic2 = 0;
        }
        if(indic2 == 11 && indic1 == 1){
            indic2 = 1;
        }
        if(indic2 == 11 && indic1 == 2){
            indic2 = 1;
        }
        if(indic2 == 2 && indic1 == 5){
            indic2 = 1;
        }
        if(indic2 == 2 && indic1 == 6){
            indic2 = 1;
        }
        if(indic2 == 1 && indic1 == 8){
            indic2 = 16;
        }
        if(indic2 == 1 && indic1 == 9){
            indic2 = 16;
        }
        if (indic2 == -1){
            indic2 = 17;
        }
}
void down_arrowkey(){
    indic1++;
        if(indic1 == 7){
            if(indic2 == 0 || indic2 == 17){
                indic1 = 0;
            }
            if(indic2 == 1){
                indic1 = 1;
            }
            if(indic2 >=2 && indic2 <= 16){
                indic1 = 8;
            }
        }
        if(indic1 == 5 && indic2 == 2){
            indic1 = 8;
        }
        if(indic1 == 10){
            if(indic2 > 1 && indic2 < 12){
                indic1 = 3;
            }
            else{
            indic1 = 1;
            }
        }
        if(indic1 == 3){
            if(indic2 == 19){
                indic1 = 0;
            }
        }
}
void up_arrowkey(){
        indic1--;
        if (indic1 == 0){
            if(indic2 == 1){
                indic1 = 6;
            }
            if(indic2 > 11 && indic2 < 17){
                indic1 = 9;
            }
        }
        if (indic1 == -1){
            if(indic2 == 0 || indic2 == 17){
                indic1 = 6;
            }
            else{
                indic1 = 2;
            }
        }
        if (indic1 == 2){
            if(indic2 >1 && indic2 <12){
                indic1 = 9;
            }
        }
        if (indic1 == 7){
            if(indic2 > 2 && indic2 < 17){
                indic1 = 6;
            }
            if(indic2 == 2){
                indic1 = 4;
            }
        }
}
void enter(){

    if(synthesis == true){
        if(count_reactant != no_reactant_1+no_reactant_2){
            *history_reactantptr = elements[indic1][indic2];
            history_reactantptr++;
            count_reactant++;
        }
        else{
            *history_productptr = elements[indic1][indic2];
            history_productptr++;
        }
    }
    if(decomposition == true){
        if(count_reactant != no_reactant_1){
            *history_reactantptr = elements[indic1][indic2];
            history_reactantptr++;
            count_reactant++;
        }
        else{
            *history_productptr = elements[indic1][indic2];
            history_productptr++;
        }
    }

    count_iteration++;
    delete history_reactantptr;
    delete history_productptr;
}
void history_menu(){         //HISTORY
cout << endl << "\t\t";
    if(synthesis = true){
        for(int i = 0; i < no_reactant_1; i++){
        cout << history_reactant[i] << "  ";
        }
            cout << " + ";
        for(int i = 0; i < no_reactant_2; i++){
        cout << history_reactant[i+no_reactant_1] << "  ";
        }
            cout << " ==> ";
        for(int i = 0; i < no_product_1; i++){
        cout << history_product[i]  << "  ";
        }
    }
    if(decomposition == true){
       for(int i = 0; i < no_reactant_1; i++){
        cout << history_reactant[i] << "  ";
        }
            cout << " + ";
        for(int i = 0; i < no_product_1; i++){
        cout << history_product[i] << "  ";
        }
            cout << " ==> ";
        for(int i = 0; i < no_product_2; i++){
        cout << history_product[i+no_product_1]  << "  ";
        }
    }
// for loop depending on the number of elements plus the number of sets

}               // HISTORY
void subscript_input(){
    count = 0;
do{
    system("CLS");

    if(synthesis == true){
        cout << "SYNTHESIS" << endl << endl;
        cout << " REACTANT  - ENTER SUBSCRIPT FOR RESPECTIVE ELEMENTS" << endl;
        for(int i = 0; i < no_reactant_1 + no_reactant_2; i++){
            cout << history_reactant[i] << " = " << subscript_reactant[i] << endl;
        }
        cout << endl;
        cout << " PRODCUCT  - ENTER SUBSCRIPT FOR RESPECTIVE ELEMENTS" << endl;
        for(int j = 0; j < no_product_1; j++){
        cout << history_product[j] << " = " << subscript_product[j] << endl;
        }
    }
    if(decomposition == true){
        cout << "DECOMPOSITION"<< endl << endl;
        cout << " REACTANT  - ENTER SUBSCRIPT FOR RESPECTIVE ELEMENTS" << endl;
        for(int i = 0; i < no_reactant_1; i++){
            cout << history_reactant[i] << " = " << subscript_reactant[i] << endl;
        }
        cout << endl;
        cout << " PRODCUCT  - ENTER SUBSCRIPT FOR RESPECTIVE ELEMENTS" << endl;
        for(int j = 0; j < no_product_1 + no_product_2; j++){
        cout << history_product[j] << " = " << subscript_product[j] << endl;
        }
    }

        if(count == 0){
            if(synthesis == true){
                for(int i = 0; i < no_reactant_1 +no_reactant_2; i++){
                cout << "Enter subscript for " << history_reactant[i] << " : ";
                cin >> subscript_reactant[i];
                }
                cout << endl;
                for(int i = 0; i < no_product_1; i++){
                cout << "Enter subscript for " << history_product[i] << " : ";
                cin >> subscript_product[i];
                }
            }
            if(decomposition == true){
                for(int i = 0; i < no_reactant_1; i++){
                cout << "Enter subscript for " << history_reactant[i] << " : ";
                cin >> subscript_reactant[i];
                }
                cout << endl;
                for(int i = 0; i < no_product_1+no_product_2; i++){
                cout << "Enter subscript for " << history_product[i] << " : ";
                cin >> subscript_product[i];
                }
            }
        }

        else if(count == 1){
            if(synthesis == true){
                if(no_reactant_1 == 1 && no_reactant_2 == 1 || no_product_1 == 2){
                    if(!(history_reactant[0] == history_product[0] && history_reactant[1] == history_product[1])){
                        cout << "It cannot be solved. Please Try Again. " << endl;
                    }
                    else{
                        n1 = subscript_reactant[0] * subscript_product[0];
                        v1 = n1/subscript_reactant[0];
                        v2 = n1/subscript_product[0];
                        t1 = (v2 *subscript_product[1])/ subscript_reactant[1];

                        cout << "\t\t BALANCED EQUATION : " << endl << endl;
                        for (int i = 0; i < 1; i++){
                            cout << v1 << history_reactant[0] << subscript_reactant[0];
                            cout << " + ";
                            cout << t1 << history_reactant[1] << subscript_reactant[0];

                        }
                        cout << " ==> ";
                        for (int i = 0; i < 1; i++){
                            cout << v2 << history_product[0] << subscript_product[0] << history_product[1] << subscript_product[1];
                            cout << endl << endl;
                        }
                    }
                }
                else if (no_reactant_1 ==2 && no_reactant_2 ==1|| no_product_1 == 3 ){
                    if (!(history_reactant[0] == history_product[0] && history_reactant[1] == history_product[1] && history_reactant[2] == history_reactant[2])){
                        cout<<"It cannot be solved. Please Try Again. " << endl;
                    }
                    else{
                        v1 = subscript_reactant[2] * subscript_product[2];
                        t1 = v1/subscript_reactant[2];
                        t2= v1/ subscript_product[2];
                        v2=t2*subscript_product[0];
                        v3=t2*subscript_product[1];
                        v4=v2*subscript_reactant[0];
                        v5=v3*subscript_reactant[1];
                        t3=v4/subscript_reactant[0];
                        t4=v5/subscript_reactant[1];

                        cout << "\t\t BALANCED EQUATION : " << endl << endl;
                        for (int i = 0; i < 1; i++){
                            cout<<t3<<history_reactant[0]<<subscript_reactant[0]<<history_reactant[1]<<subscript_reactant[1];
                            cout<<" + ";
                            cout<<t1<<history_reactant[2]<<subscript_reactant[2];
                        }
                        cout<<"\t------> \t";
                        for (int i=0;i<1;i++){
                        cout<<t2<<history_product[0]<<subscript_product[0]<<history_product[1]<<subscript_product[1]<<history_product[2]<<subscript_product[2];
                        cout<<endl<<endl;}
                    }
                }
            }
            if(decomposition == true){
                if (no_reactant_1 == 2 && no_product_1 ==1&& no_product_2 ==1){
                    if (!(history_reactant[0]==history_product[0] && history_reactant[1] ==history_product[1])){
                    cout << "It cannot be solved. Please try again. " << endl;
                    }
                    else{
                        v1= subscript_reactant[1] * subscript_product[1];
                        t1=v1/subscript_reactant[1];
                        t2=v1/subscript_product[1];
                        v2=t1*subscript_reactant[0];
                        t3=v2/subscript_product[0];

                        cout << "\t\t BALANCED EQUATION : " << endl << endl;
                        for (int i = 0; i < 1; i++){
                            cout<<t1<<history_reactant[0]<<subscript_reactant[0]<<history_reactant[1]<<subscript_reactant[1];
                            cout<<" + ";
                        }
                        cout<<"\t------> \t";
                        for (int i=0;i<1;i++){
                            cout<<t3<<history_product[0]<<subscript_product[0];
                            cout<<"	+	";
                            cout<<t2<<history_product[1]<<subscript_product[1];
                            cout<<endl<<endl;
                        }
                    }
                }
            }
                else if (no_reactant_1 == 3 && no_product_1 ==2&& no_product_2 ==1){
                    if (!(history_reactant[0] == history_product[0] && history_reactant[1] == history_product[1] && history_reactant[2] == history_reactant[2])){
                        cout << "It cannot be solved. Please try again. " << endl;
                    }
                    else{
                        v1 = subscript_reactant[2] * subscript_product[2];
                        t1 = v1/subscript_reactant[2];
                        t2=v1/subscript_product[2];
                        v2=t1*subscript_product[0];
                        t3=v2/subscript_product[0];

                        cout << "\t\t BALANCED EQUATION : " << endl << endl;
                        for (int i=0;i<1;i++){
                        cout<<t1<<history_reactant[0]<<subscript_reactant[0]<<subscript_reactant[1]<<subscript_reactant[1]<<history_reactant[2]<<subscript_reactant[2];
                        }
                        cout<<"\t------> \t";
                        for (int i=0;i<1;i++){
                        cout<<t3<<history_product[0]<<subscript_product[0]<<history_product[1]<<subscript_product[1];
                        cout<<"	+	";
                        cout<<t2<<history_product[2]<<subscript_product[2];
                        cout<<endl<<endl;
                        }
                    }
                }
            }

count++;
}
while(count < 2);
}//////////////


int main(){

do{
for(int i = 0; i < 10; i++){
    history_reactant[i] = "__";
    history_product[i] = "__";
}
count_iteration = 0;
continues = ' ';
stop = false;
synthesis = false;
decomposition = false;

system("CLS");
userinput1(); //                USER INPUT

while (stop == false){
    system("CLS");


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "\n\t\t\t\t\t TABLE OF ELEMENTS\n\n" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "\t\tInstructions: Use Space Bar to Enter the wished Element or Commmand" << endl << endl;
    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 20; j++){

            if (i == indic1 && j == indic2){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);
            cout << elements[i][j] << "   ";
            }
            else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cout << elements[i][j] << "   ";
            }
        }
    cout << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    history_menu();  //             HISTORY OUTPUT

while (stop == false){
    if (GetAsyncKeyState(VK_RIGHT) != 0){
    right_arrowkey();
    break;
    }
    else if(GetAsyncKeyState(VK_LEFT)!=0){
    left_arrowkey();
    break;
    }
    else if(GetAsyncKeyState(VK_DOWN)!=0){
    down_arrowkey();
    break;
    }
    else if(GetAsyncKeyState(VK_UP)!=0){
    up_arrowkey();
    break;
    }

    if (GetAsyncKeyState(VK_SPACE)!=0){
    enter();
    break;
    }
    if (GetAsyncKeyState(VK_RETURN)!=0){
        break;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    if (count_iteration == no_iteration ){
        stop = true;
    }
}
Sleep(90);
}

subscript_input();



system("pause");
cout << endl << "Do you want to continue?? [Y / N] ";
cin >> continues;
no_reactant = no_reactant_1 + no_reactant_2;
no_product = no_reactant_1 + no_reactant_2;
for (int i = 0; i <= no_reactant; i++){
    history_reactantptr--;
}
for(int i = 0; i <= no_product; i++){
    history_productptr--;
}
delete history_reactantptr;
delete history_productptr;
count_reactant = 0;
count_product = 0;
}
while (continues == 'Y' || continues == 'y');




return 0;
}



