#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

//Alyza Rahima Pramudya - 2502032125

#define CLR_PURP "\e[0;35m" //To Define ANSI color of purple
#define CLR_WHT "\e[0;37m" //To Define ANSI color of white

struct pharmacy{         //struct to store all patients in pharmacy
	char name[1005];
	char medicine[1005];
	char diagnostic[1005];
	char costadministrasi[105];
	char costdoctor[105];
	char costmedicine[105];
	char status[105];
}pharmacyqueue[1000];

struct patientdata{      //struct to store basic patient's data
    int no;
    char name[105];
    char birth[105];
    char age[105];
    char address[105];
    char status[105];
    struct patientdata *next;
};

struct detaildata{        //struct to store clinics and doctors data
    char clinics[105];
    char doctor[105];
    char treatment[1005];
    char costdoctor[105];
    struct detaildata *next;
    struct patientdata *list;
};

struct patientdata *patient = NULL;
struct detaildata *alldata = NULL;

char neurologist[105][105] = {"Neurotam", "Gabapentin", "Tegretol"}; //list of medicines in neurologist
char orthopedics[105][105] = {"RoActemra", "Neo rheumacyl", "Counterpain"}; //list of medicines in orthopedics
char dental[105][105] = {"Asam Mefenamat", "Amoxicilin", "Panadol"}; //list of medicines in dental
char pedriatic[105][105] = {"Profis", "Panadol Anak", "Bisolvon kids"}; //list of medicines in pedriatic
char clinic[105][105] = {"Neurologist", "Orthopedics", "Dental", "Pedriatic"}; //list of clinics
char price[105][105] = {"250000", "100000", "125000", "70000", "50000", "35000", "20000"}; //list of price
int no[8] ={0,0,0,0,0,0,0,0}; //queue number of each doctor

int PTQ = 0, MDR=0; //PTQ number of patient queues //MDR number of patient queues to be

void delay()  //function To delay the program
{
    for (int i = 0; i < 2e7; i++){
    }
}

void ascii_mainMenuAnimated(){ //function for Animated Title
 
    printf(" _       __     __                             ______         ___    ____  ____           __  __                 _ __        __\n");
    delay();
    printf("| |     / /__  / /________  ____ ___  ___     /_  __/___     /   |  / __ \\/ __ \\____ _   / / / /___  _________  (_) /_____ _/ /\n");
    delay();
    printf("| | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\     / / / __ \\   / /| | / /_/ / /_/ / __ `/  / /_/ / __ \\/ ___/ __ \\/ / __/ __ `/ / \n");
    delay();
    printf("| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/    / / / /_/ /  / ___ |/ ____/ _, _/ /_/ /  / __  / /_/ (__  ) /_/ / / /_/ /_/ / /  \n");
    delay();
    printf("|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___/    /_/  \\____/  /_/  |_/_/   /_/ |_|\\__,_/  /_/ /_/\\____/____/ .___/_/\\__/\\__,_/_/   \n");
    delay();
    printf("                                                                                                      /_/                      \n");

}

void ascii_mainMenu(){
 
    printf(" _       __     __                             ______         ___    ____  ____           __  __                 _ __        __\n");
    printf("| |     / /__  / /________  ____ ___  ___     /_  __/___     /   |  / __ \\/ __ \\____ _   / / / /___  _________  (_) /_____ _/ /\n");
    printf("| | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\     / / / __ \\   / /| | / /_/ / /_/ / __ `/  / /_/ / __ \\/ ___/ __ \\/ / __/ __ `/ / \n");
    printf("| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/    / / / /_/ /  / ___ |/ ____/ _, _/ /_/ /  / __  / /_/ (__  ) /_/ / / /_/ /_/ / /  \n");
    printf("|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___/    /_/  \\____/  /_/  |_/_/   /_/ |_|\\__,_/  /_/ /_/\\____/____/ .___/_/\\__/\\__,_/_/   \n");
    printf("                                                                                                      /_/                      \n");

}

void ascii_exiAnimated(){
    
    printf("  ________                __      __  __               __   __\n");
    delay();
    printf(" /_  __/ /_  ____ _____  / /__    \\ \\/ /___  __  __   / /  / /\n");
    delay();
    printf("  / / / __ \\/ __ `/ __ \\/ //_/     \\  / __ \\/ / / /  / /  / / \n");
    delay();
    printf(" / / / / / / /_/ / / / / ,<        / / /_/ / /_/ /  /_/  /_/  \n");
    delay();
    printf("/_/ /_/ /_/\\__,_/_/ /_/_/|_|      /_/\\____/\\__,_/  (_)  (_)   \n");
                                                              
}

void ascii_displayAnimated(){
    
    printf("     _________       _              ___              __   ____             __                 \n");
    delay();
    printf("    / ____/ (_)___  (_)_________   /   |  ____  ____/ /  / __ \\____  _____/ /_____  __________\n");
    delay();
    printf("   / /   / / / __ \\/ / ___/ ___/  / /| | / __ \\/ __  /  / / / / __ \\/ ___/ __/ __ \\/ ___/ ___/\n");
    delay();
    printf("  / /___/ / / / / / / /__(__  )  / ___ |/ / / / /_/ /  / /_/ / /_/ / /__/ /_/ /_/ / /  (__  ) \n");
    delay();
    printf("  \\____/_/_/_/ /_/_/\\___/____/  /_/  |_/_/ /_/\\__,_/  /_____/\\____/\\___/\\__/\\____/_/  /____/  \n");
                                                                                            

}

void ascii_registrasiAnimated(){
        
    printf("    ____             _      __             __  _           \n");
    delay();
    printf("   / __ \\___  ____ _(_)____/ /__________ _/ /_(_)___  ____ \n");
    delay();
    printf("  / /_/ / _ \\/ __ `/ / ___/ __/ ___/ __ `/ __/ / __ \\/ __ \\\n");
    delay();
    printf(" / _, _/  __/ /_/ / (__  ) /_/ /  / /_/ / /_/ / /_/ / / / /\n");
    delay();
    printf("/_/ |_|\\___/\\__, /_/____/\\__/_/   \\__,_/\\__/_/\\____/_/ /_/ \n");
    delay();
    printf("           /____/                                          \n");

}

void ascii_registrasi(){
        
    printf("   ____              _      __             __  _           \n");
    printf("   / __ \\___  ____ _(_)____/ /__________ _/ /_(_)___  ____ \n");
    printf("  / /_/ / _ \\/ __ `/ / ___/ __/ ___/ __ `/ __/ / __ \\/ __ \\\n");
    printf(" / _, _/  __/ /_/ / (__  ) /_/ /  / /_/ / /_/ / /_/ / / / /\n");
    printf("/_/ |_|\\___/\\__, /_/____/\\__/_/   \\__,_/\\__/_/\\____/_/ /_/ \n");
    printf("           /____/                                          \n");

}

void ascii_queueAnimated(){
    
    printf("    ____             __                     ____                      \n");
    delay();
    printf("   / __ \\____  _____/ /_____  __________   / __ \\__  _____  __  _____ \n");
    delay();
    printf("  / / / / __ \\/ ___/ __/ __ \\/ ___/ ___/  / / / / / / / _ \\/ / / / _ \\\n");
    delay();
    printf(" / /_/ / /_/ / /__/ /_/ /_/ / /  (__  )  / /_/ / /_/ /  __/ /_/ /  __/\n");
    delay();
    printf("/_____/\\____/\\___/\\__/\\____/_/  /____/   \\___\\_\\__,_/\\___/\\__,_/\\___/ \n");
                                                                      

}

void ascii_queue(){
    
    printf("    ____             __                     ____                      \n");
    printf("   / __ \\____  _____/ /_____  __________   / __ \\__  _____  __  _____ \n");
    printf("  / / / / __ \\/ ___/ __/ __ \\/ ___/ ___/  / / / / / / / _ \\/ / / / _ \\\n");
    printf(" / /_/ / /_/ / /__/ /_/ /_/ / /  (__  )  / /_/ / /_/ /  __/ /_/ /  __/\n");
    printf("/_____/\\____/\\___/\\__/\\____/_/  /____/   \\___\\_\\__,_/\\___/\\__,_/\\___/ \n");                                                           

}

void ascii_callpatientAnimated(){
    
    printf("   ______      ____   ____        __  _            __ \n");
    delay();
    printf("  / ____/___ _/ / /  / __ \\____ _/ /_(_)__  ____  / /_\n");
    delay();
    printf(" / /   / __ `/ / /  / /_/ / __ `/ __/ / _ \\/ __ \\/ __/\n");
    delay();
    printf("/ /___/ /_/ / / /  / ____/ /_/ / /_/ /  __/ / / / /_  \n");
    delay();
    printf("\\____/\\__,_/_/_/  /_/    \\__,_/\\__/_/\\___/_/ /_/\\__/  \n");
                                            
}

void ascii_callpatient(){
    
    printf("   ______      ____   ____        __  _            __ \n");
    printf("  / ____/___ _/ / /  / __ \\____ _/ /_(_)__  ____  / /_\n");
    printf(" / /   / __ `/ / /  / /_/ / __ `/ __/ / _ \\/ __ \\/ __/\n");
    printf("/ /___/ /_/ / / /  / ____/ /_/ / /_/ /  __/ / / / /_  \n");
    printf("\\____/\\__,_/_/_/  /_/    \\__,_/\\__/_/\\___/_/ /_/\\__/  \n");
                                            
}

void ascii_pharmacyAnimated(){
    
    printf("    ____  __                                         \n");
    delay();
    printf("   / __ \\/ /_  ____ __________ ___  ____ ________  __\n");
    delay();
    printf("  / /_/ / __ \\/ __ `/ ___/ __ `__ \\/ __ `/ ___/ / / /\n");
    delay();
    printf(" / ____/ / / / /_/ / /  / / / / / / /_/ / /__/ /_/ / \n");
    delay();
    printf("/_/   /_/ /_/\\__,_/_/  /_/ /_/ /_/\\__,_/\\___/\\__, /  \n");
    delay();
    printf("                                           /____/   \n");

}

void ascii_paymentAnimated(){
    
    printf("    ____                                   __ \n");
    delay();
    printf("   / __ \\____ ___  ______ ___  ___  ____  / /_\n");
    delay();
    printf("  / /_/ / __ `/ / / / __ `__ \\/ _ \\/ __ \\/ __/\n");
    delay();
    printf(" / ____/ /_/ / /_/ / / / / / /  __/ / / / /_  \n");
    delay();
    printf("/_/    \\__,_/\\__, /_/ /_/ /_/\\___/_/ /_/\\__/  \n");
    delay();
    printf("           /____/                            \n");

}

struct detaildata *copydata() { //function to copy the data to the struct

    struct detaildata *curr;
    curr = (struct detaildata *)malloc(sizeof(struct detaildata));

    struct detaildata *temp = curr;
    strcpy(curr->clinics, clinic[0]);
    strcpy(curr->doctor, "Alyza");
    strcpy(curr->treatment, "Monday-Friday (8AM-10PM)");
    strcpy(curr->costdoctor,"150000");
    curr->list=NULL;
    
    curr->next = (struct detaildata *)malloc(sizeof(struct detaildata));
    curr = curr->next;
    strcpy(curr->clinics, clinic[0]);
    strcpy(curr->doctor, "Peter");
    strcpy(curr->treatment, "Thursday-Saturday (8AM-8PM)");
    strcpy(curr->costdoctor,"200000");
    curr->list=NULL;

    curr->next = (struct detaildata *)malloc(sizeof(struct detaildata));
    curr = curr->next;
    strcpy(curr->clinics, clinic[1]);
    strcpy(curr->doctor, "Akbar");
    strcpy(curr->treatment, "Monday-Wednesday (10AM-10PM)");
    strcpy(curr->costdoctor,"80000");
    curr->list=NULL;

    curr->next = (struct detaildata *)malloc(sizeof(struct detaildata));
    curr = curr->next;
    strcpy(curr->clinics, clinic[1]);
    strcpy(curr->doctor, "Rifatu");
    strcpy(curr->treatment, "Thursday-Sunday (11AM-9PM)");
    strcpy(curr->costdoctor,"125000");
    curr->list=NULL;

    curr->next = (struct detaildata *)malloc(sizeof(struct detaildata));
    curr = curr->next;
    strcpy(curr->clinics, clinic[2]);
    strcpy(curr->doctor, "Shafa");
    strcpy(curr->treatment, "Monday-Thuesday (10AM-8PM)");
    strcpy(curr->costdoctor,"150000");
    curr->list=NULL;

    curr->next = (struct detaildata *)malloc(sizeof(struct detaildata));
    curr = curr->next;
    strcpy(curr->clinics, clinic[2]);
    strcpy(curr->doctor, "Sharfina");
    strcpy(curr->treatment, "Friday-Sunday (10AM-8PM)");
    strcpy(curr->costdoctor,"100000");
    curr->list=NULL;

    curr->next = (struct detaildata *)malloc(sizeof(struct detaildata));
    curr = curr->next;
    strcpy(curr->clinics, clinic[3]);
    strcpy(curr->doctor, "Keli");
    strcpy(curr->treatment, "Monday-Friday (10AM-8PM)");
    strcpy(curr->costdoctor,"250000");
    curr->list=NULL;

    curr->next = (struct detaildata *)malloc(sizeof(struct detaildata));
    curr = curr->next;
    strcpy(curr->clinics, clinic[3]);
    strcpy(curr->doctor, "Sudarso");
    strcpy(curr->treatment, "Monday-Saturday (9AM-9PM)");
    strcpy(curr->costdoctor,"100000");
    curr->list=NULL;

    curr->next = NULL;

    return temp;
}

struct detaildata *display(struct detaildata *alldata){  //function to display list of clinics and dctors
    struct detaildata *curr;
    curr = alldata;

    ascii_displayAnimated();
    printf("\n\n");

    for(int i = 0; i < 4; i++){
        printf("\t\t\t+==============+ %s +==============+\n", clinic[i]);
        for(int j = 0; j< 2; j++){
            printf("\n\t\t\tDoctor's Name : %s", curr->doctor);
            printf("\n\t\t\tSchedule      : %s", curr->treatment);
            printf("\n\t\t\tCost          : %s\n\n", curr->costdoctor);
            curr = curr->next;
        }
    }

    printf("\n\t\t\tPress any key to continue ");
    getch();
    return alldata;
};

struct detaildata *Registrasi(struct detaildata *){  //function to input patient
    int n = 1;

    ascii_registrasiAnimated();
    printf("\n\n");

    struct detaildata *curr;
    curr = (struct detaildata *)malloc(sizeof(struct detaildata));
    struct detaildata *temp = curr;
    struct patientdata *currp;

    if(curr->list == NULL){
        currp = (struct patientdata *)malloc(sizeof(struct patientdata));
    }

    curr = alldata;

    printf("\t %s> %s <%s\n", CLR_PURP, clinic[0], CLR_WHT);
    for(int i = 1; i<4; i++){
        printf("\t %s\n", clinic[i]);
    }
    printf("\n");

    int input, count = 0;
    char choice;
    char clinicchoice[4][50] = {"Neurologist", "Orthopedics", "Dental", "Pedriatic"};
    int inputchoice = 0;

    for(int i = 0;; i++){
        choice = _getche();
        system("CLS");
        ascii_registrasi();
        printf("\n\n");

        if (choice == 's'){
            inputchoice++;
        }else if(choice == 'w'){
            inputchoice--;
        }

        if(inputchoice < 0){
            inputchoice = 0;
        }else if(inputchoice > 3){
            inputchoice = 3;
        }

        if(choice == '\x0D' && inputchoice == 0){
            input = 0;
            break;
        }else if(choice == '\x0D' && inputchoice == 1){
            input = 1;
            break;
        }else if(choice == '\x0D' && inputchoice == 2){
            input = 2;
            break;
        }else if(choice == '\x0D' && inputchoice == 3){
            input = 3;
            break;
        }

        for(int i = 0; i<4; i++){
            if(i != inputchoice){
                printf("\t %s\n", clinicchoice[i]);
            }else{
                printf("\t %s> %s <%s\n", CLR_PURP, clinicchoice[inputchoice], CLR_WHT);
            }
        }
    }

    system("CLS");
    ascii_registrasi();
    printf("\n\n");

    while(1){
        if(strcmp(curr->clinics, clinic[input])==0){
            break;
        }else{
            curr = curr->next;
            count++;
        }
    }

    for(int i = 0; i<2; i++){
        printf("\n\t(%d)", i+1);
        printf("\n\tDoctor's Name : %s", curr->doctor);
        printf("\n\tSchedule      : %s", curr->treatment);
        printf("\n\tCost          : %s\n\n", curr->costdoctor);
        curr = curr->next;
    }
    printf("\t>> "); scanf("%d", &input); getchar();
    curr = alldata;
    for(int i = 0; i<count + input-1; i++){
        curr = curr->next;
    }
    currp = curr->list;

    no[count+input-1] += 1;

    if(currp == NULL){
        currp = (struct patientdata *)malloc(sizeof(struct patientdata));
        curr->list = currp;
    }else{
        while(currp->next != NULL){
            currp = currp->next;
        }
        currp->next = (struct patientdata *)malloc(sizeof(struct patientdata));
        currp = currp->next;
    }

    system("CLS");
    ascii_registrasi();
    printf("\n\n");
    char str[1005];
    printf("\tName                               : "); scanf("%[^\n]", &str); getchar(); strcpy(currp->name, str);
    printf("\n\tBirth of Date                      : "); scanf("%[^\n]", &str); getchar(); strcpy(currp->birth, str);
    printf("\n\tAge                                : "); scanf("%[^\n]", &str); getchar(); strcpy(currp->age, str);
    printf("\n\tAddress                            : "); scanf("%[^\n]", &str); getchar(); strcpy(currp->address, str);
    printf("\n\tStatus (BPJS / Inhealth / Mandiri) : "); scanf("%[^\n]", &str); getchar(); 

    strcpy(currp->status, str);
    currp->no = no[count+input-1];

    system("CLS");
    ascii_registrasi();
    printf("\n\n");

    printf("\n\t(%d)", currp->no);
    printf("\n\tPatient's Name   : %s", currp->name);
    printf("\n\tClinic           : %s", curr->clinics);
    printf("\n\tDoctor's Name    : %s", curr->doctor);

    printf("\n\n\tPress Any Key To Continue "); getch();
    currp->next = NULL;

    return alldata;
};

struct detaildata *Queue(struct detaildata *alldata){  //function to show doctor's queue
    system("CLS");
    ascii_queueAnimated();
    printf("\n\n");

    int n=1;
    struct detaildata *curr;
    curr = alldata;
    struct patientdata *currp;

    printf("\t\t %s> %s <%s\n", CLR_PURP, clinic[0], CLR_WHT);
    for(int i = 1; i<4; i++){
        printf("\t\t%s\n", clinic[i]);
    }
    printf("\n");

    int input, count = 0;
    char choice;
    char clinicchoice[4][50] = {"Neurologist", "Orthopedics", "Dental", "Pedriatic"};
    int inputchoice = 0;

    for(int i = 0;; i++){
        choice = _getche();
        system("CLS");
        ascii_queue();
        printf("\n\n");

        if (choice == 's'){
            inputchoice++;
        }else if(choice == 'w'){
            inputchoice--;
        }

        if(inputchoice < 0){
            inputchoice = 0;
        }else if(inputchoice > 3){
            inputchoice = 3;
        }

        if(choice == '\x0D' && inputchoice == 0){
            input = 0;
            break;
        }else if(choice == '\x0D' && inputchoice == 1){
            input = 1;
            break;
        }else if(choice == '\x0D' && inputchoice == 2){
            input = 2;
            break;
        }else if(choice == '\x0D' && inputchoice == 3){
            input = 3;
            break;
        }

        for(int i = 0; i<4; i++){
            if(i != inputchoice){
                printf("\t\t %s\n", clinicchoice[i]);
            }else{
                printf("\t\t %s> %s <%s\n", CLR_PURP, clinicchoice[inputchoice], CLR_WHT);
            }
        }
    }

    system("CLS");
    ascii_queue();
    printf("\n\n");

    while(1){
        if(strcmp(curr->clinics, clinic[input])==0){
            break;
        }else{
            curr = curr->next;
            count++;
        }
    }

    currp = curr->list;
    int it = 0;

    printf("\t\t %s's Queue\n", curr->doctor);
    if(currp != NULL){
        while(currp != NULL){
            it++;
            printf("\t\t No Queue         : %d\n", it);
            printf("\t\t Patient's Name   : %s\n\n", currp->name);
            currp = currp->next;
        }
    }else{
        printf("\t\t %s's doesn't have any queue for now\n\n", curr->doctor);
    }

    curr = curr->next;
    currp = curr->list;
    it = 0;
    printf("\t\t %s's Queue\n", curr->doctor);
    if(currp != NULL){
        while(currp != NULL){
            it++;
            printf("\t\t No Queue         : %d\n", it);
            printf("\t\t Patient's Name   : %s\n\n", currp->name);
            currp = currp->next;
        }
    }else{
        printf("\t\t %s's doesn't have any queue for now\n\n", curr->doctor);
    }

    printf("\t\t Press Any Key To Continue "); getch();
    return alldata;

};

struct detaildata *callpatient(struct detaildata *alldata){  //function to call the patient

    ascii_callpatientAnimated();
    printf("\n\n");

    fflush(stdin);

    int n = 1;
    struct detaildata *curr;
    curr = alldata;
    struct detaildata *temp = curr;
    struct patientdata *currp;

    printf("\t\t %s> %s <%s\n", CLR_PURP, clinic[0], CLR_WHT);
    for(int i = 1; i<4; i++){
        printf("\t\t%s\n", clinic[i]);
    }
    printf("\n");

    int input, count = 0;
    char choice;
    char clinicchoice[4][50] = {"Neurologist", "Orthopedics", "Dental", "Pedriatic"};
    int inputchoice = 0;

    for(int i = 0;; i++){
        choice = _getche();
        system("CLS");
        ascii_callpatient();
        printf("\n\n");

        if (choice == 's'){
            inputchoice++;
        }else if(choice == 'w'){
            inputchoice--;
        }

        if(inputchoice < 0){
            inputchoice = 0;
        }else if(inputchoice > 3){
            inputchoice = 3;
        }

        if(choice == '\x0D' && inputchoice == 0){
            input = 0;
            break;
        }else if(choice == '\x0D' && inputchoice == 1){
            input = 1;
            break;
        }else if(choice == '\x0D' && inputchoice == 2){
            input = 2;
            break;
        }else if(choice == '\x0D' && inputchoice == 3){
            input = 3;
            break;
        }

        for(int i = 0; i<4; i++){
            if(i != inputchoice){
                printf("\t\t %s\n", clinicchoice[i]);
            }else{
                printf("\t\t %s> %s <%s\n", CLR_PURP, clinicchoice[inputchoice], CLR_WHT);
            }
        }
    }

    fflush(stdin);

    system("CLS");
    ascii_callpatient();
    printf("\n\n");

    while(1){
        if(strcmp(curr->clinics, clinic[input])==0){
            break;
        }else{
            curr = curr->next;
            count++;
        }
    }

    fflush(stdin);

    for(int i = 0; i<2; i++){
        printf("\n\t\t(%d)", i+1);
        printf("\n\t\tDoctor's Name : %s", curr->doctor);
        printf("\n\t\tSchedule      : %s\n\n", curr->treatment);
        curr = curr->next;
    }
    printf("\n\n\t\t>> "); scanf("%d", &input); getchar();
    curr = alldata;
    for(int i = 0; i<count + input-1; i++){
        curr = curr->next;
    }
    currp = curr->list;

    system("CLS");
    ascii_callpatient();
    printf("\n\n");

    if(currp == NULL){
        printf("\n\t\t%s doesn't have any patient for now\n\n");
        printf("\t\tPress Any Key To Continue "); getch();
        return alldata;
    }

    strcpy(pharmacyqueue[PTQ].name, currp->name);
    printf("\n\t\t%s's Diagnose  : ", currp->name);
    
    int d;
    if(strcmp(curr->clinics, clinic[0])==0){
        printf("\n\t\t1. Memory Disorder");
        printf("\n\t\t2. Seizure");
        printf("\n\t\t3. Epilepsi");
        printf("\n\t\t>> "); scanf("%d", &d); getchar();
        if(d == 1){
            strcpy(pharmacyqueue[PTQ].diagnostic, "Memory Disorder");
            strcpy(pharmacyqueue[PTQ].medicine, neurologist[0]); //Neurotam
            strcpy(pharmacyqueue[PTQ].costmedicine, price[1]); //100.000
        }else if(d == 2){
            strcpy(pharmacyqueue[PTQ].diagnostic, "Seizure");
            strcpy(pharmacyqueue[PTQ].medicine, neurologist[1]); //Gabapentin
            strcpy(pharmacyqueue[PTQ].costmedicine, price[3]); //70.000
        }else if(d == 3){
            strcpy(pharmacyqueue[PTQ].diagnostic, "Epilepsi");
            strcpy(pharmacyqueue[PTQ].medicine, neurologist[2]); //Tegretol
            strcpy(pharmacyqueue[PTQ].costmedicine, price[2]); //125.000
        }
    }else if(strcmp(curr->clinics, clinic[1])==0){
        printf("\n\t\t1. Rheumatoid Arthritis");
        printf("\n\t\t2. Muscle Ache");
        printf("\n\t\t3. Joint Pain");
        printf("\n\t\t>> "); scanf("%d", &d); getchar();
        if(d == 1){
            strcpy(pharmacyqueue[PTQ].diagnostic, "Rheumatoid Arthritis");
            strcpy(pharmacyqueue[PTQ].medicine, orthopedics[0]); //RoActemra
            strcpy(pharmacyqueue[PTQ].costmedicine, price[0]); //200.000
        }else if(d == 2){
            strcpy(pharmacyqueue[PTQ].diagnostic, "Muscle Ache");
            strcpy(pharmacyqueue[PTQ].medicine, orthopedics[1]); //Neo Rheumacyl
            strcpy(pharmacyqueue[PTQ].costmedicine, price[6]); //20.000
        }else if(d == 3){
            strcpy(pharmacyqueue[PTQ].diagnostic, "Joint Pain");
            strcpy(pharmacyqueue[PTQ].medicine, orthopedics[2]); //Counterpain
            strcpy(pharmacyqueue[PTQ].costmedicine, price[4]); //50.000
        }
    }else if(strcmp(curr->clinics, clinic[2])==0){
        printf("\n\t\t1. Tootache");
        printf("\n\t\t2. Abscess");
        printf("\n\t\t3. Dizzy Because of Toothache");
        printf("\n\t\t>> "); scanf("%d", &d); getchar();
        if(d == 1){
            strcpy(pharmacyqueue[PTQ].diagnostic, "Toothache"); 
            strcpy(pharmacyqueue[PTQ].medicine, dental[0]); //Asam Mefenemat
            strcpy(pharmacyqueue[PTQ].costmedicine, price[6]); //20.000
        }else if(d == 2){
            strcpy(pharmacyqueue[PTQ].diagnostic, "Abscess");
            strcpy(pharmacyqueue[PTQ].medicine, dental[1]); //Amoxicilin
            strcpy(pharmacyqueue[PTQ].costmedicine, price[6]); //20.000
        }else if(d == 3){
            strcpy(pharmacyqueue[PTQ].diagnostic, "Dizzy Cause of Tootache");
            strcpy(pharmacyqueue[PTQ].medicine, dental[2]); //Panadol
            strcpy(pharmacyqueue[PTQ].costmedicine, price[6]); //20.000
        }
    }else if(strcmp(curr->clinics, clinic[3])==0){
        printf("\n\t\t1. Fever");
        printf("\n\t\t2. Dizzy");
        printf("\n\t\t3. Cough");
        printf("\n\t\t>> "); scanf("%d", &d); getchar();
        if(d == 1){
            strcpy(pharmacyqueue[PTQ].diagnostic, "Fever");
            strcpy(pharmacyqueue[PTQ].medicine, pedriatic[0]); //Profis
            strcpy(pharmacyqueue[PTQ].costmedicine, price[5]); //35.000
        }else if(d == 2){
            strcpy(pharmacyqueue[PTQ].diagnostic, "Dizzy");
            strcpy(pharmacyqueue[PTQ].medicine, pedriatic[1]); //Panadol Anak
            strcpy(pharmacyqueue[PTQ].costmedicine, price[4]); //50.000
        }else if(d == 3){
            strcpy(pharmacyqueue[PTQ].diagnostic, "Cough");
            strcpy(pharmacyqueue[PTQ].medicine, pedriatic[2]); //Bisolvon Kids
            strcpy(pharmacyqueue[PTQ].costmedicine, price[4]); //50.000
        }
    }

    strcpy(pharmacyqueue[PTQ].status, currp->status);
    strcpy(pharmacyqueue[PTQ].costadministrasi, "50000");
    strcpy(pharmacyqueue[PTQ].costdoctor, curr->costdoctor);
    PTQ++;

    FILE *fp;
    fp = fopen("MedicalRecords.txt", "a");
    fprintf(fp, "%s#%s#%s#%s#%s#\n", currp->name, currp->birth, currp->age, currp->address, currp->status);
    fclose(fp);
    
    if(curr->list !=NULL){
        curr->list = currp->next;
        return alldata;
        free(curr);
    }
    return alldata;
};

void displaypharmacy(){ //function to display pharmacy queue
    ascii_pharmacyAnimated();
    printf("\n\n");

    int a=1;
    for(int i = MDR; i<PTQ; i++){
        printf("\n\t(%d)", a);
        printf("\n\tName            : %s", pharmacyqueue[i].name);
        printf("\n\tDiagnose        : %s", pharmacyqueue[i].diagnostic);
        printf("\n\tMedicine        : %s", pharmacyqueue[i].medicine);
        printf("\n\tMedicine Price  : %s\n\n", pharmacyqueue[i].costmedicine);
        a++;
    }

    printf("\n\n\tPress Any Key To continue "); getch();
};

void deletepharmacy(){  //function to make a payment
    ascii_paymentAnimated();
    printf("\n\n");

    long long int sum = atoi(pharmacyqueue[MDR].costadministrasi)+ atoi(pharmacyqueue[MDR].costdoctor)+ atoi(pharmacyqueue[MDR].costmedicine);

    if(strcmp(pharmacyqueue[MDR].name, "")!=0){
        if(strcmp(pharmacyqueue[MDR].status, "BPJS")!=0 && strcmp(pharmacyqueue[MDR].status, "Inhealth")!=0){
            printf("\n\tName                : %s", pharmacyqueue[MDR].name);
            printf("\n\tAdministration Cost : %s", pharmacyqueue[MDR].costadministrasi);
            printf("\n\tDoctor Cost         : %s", pharmacyqueue[MDR].costdoctor);
            printf("\n\tMedicine Cost       : %s", pharmacyqueue[MDR].costmedicine);
            printf("\n\tInsurance           : No");
            printf("\n\t================================\n");
            printf("\tTotal Payment       :  %lld\n\n", sum);

            printf("\tComplete Transaction Process "); getch();
            system("CLS");
            ascii_exiAnimated();
            printf("\n\n\tPress Any Key To Continue ");getch();
        }else{
            printf("\n\tName                : %s", pharmacyqueue[MDR].name);
            printf("\n\tAdministration Cost : %s", pharmacyqueue[MDR].costadministrasi);
            printf("\n\tDoctor Cost         : %s", pharmacyqueue[MDR].costdoctor);
            printf("\n\tMedicine Cost       : %s", pharmacyqueue[MDR].costmedicine);
            printf("\n\tInsurance           : Yes");
            printf("\n\t================================\n");
            printf("\tTotal Payment       :  0");
            printf("\n\tAll Payment Has Been Covered By %s Get Well Soon!\n\n", pharmacyqueue[MDR].status);
            printf("\n\tPress Any Key To Continue "); getch();
        }
    }

    FILE *fp;
    fp = fopen("MedicalRecords.txt", "a");
    fprintf(fp, "%s#%s#%s#%s#%s#%s#%s#\n", pharmacyqueue[MDR].name, pharmacyqueue[MDR].diagnostic, pharmacyqueue[MDR].medicine, pharmacyqueue[MDR].costmedicine, pharmacyqueue[MDR].costdoctor, pharmacyqueue[MDR].costadministrasi, pharmacyqueue[MDR].status);
    fclose(fp);
    MDR++;
};

int main(){  //main function
    int menu;
    alldata = copydata();

    while(1){
        system("CLS");
        ascii_mainMenuAnimated();
        printf("\n\n");
        printf("\t\t\t\t\t\t %s> List Doctors & Clinics<%s\n", CLR_PURP, CLR_WHT);
        printf("\t\t\t\t\t\t Input Patient\n");
        printf("\t\t\t\t\t\t Display Doctors Queue\n");
        printf("\t\t\t\t\t\t Call Patient\n");
        printf("\t\t\t\t\t\t Display Pharmacy Queue\n");
        printf("\t\t\t\t\t\t Call Patient for Payment\n");
        printf("\t\t\t\t\t\t Exit\n");

        char input;
        char logins[7][150] = {"List Doctors & Clinics", "Input Patient", "Display Doctors Queue", "Call Patient", "Display Pharmacy Queue", "Call Patient for Payment", "Exit"};

        int inputchoice = 0;

        for(int i = 0;; i++){
            input = _getche();
            system("CLS");
            ascii_mainMenu();
            printf("\n\n");

            if (input == 's'){
                inputchoice++;
            }else if(input == 'w'){
                inputchoice--;
            }

            if(inputchoice < 0){
                inputchoice = 0;
            }else if(inputchoice > 6){
                inputchoice = 6;
            }

            if(input == '\x0D' && inputchoice == 0){
                system("CLS");
                alldata = display(alldata);
                system("CLS");
                ascii_mainMenu();
                printf("\n\n");
            }else if(input == '\x0D' && inputchoice == 1){
                system("CLS");
                alldata = Registrasi(alldata);
                system("CLS");
                ascii_mainMenu();
                printf("\n\n");
            }else if(input == '\x0D' && inputchoice == 2){
                system("CLS");
                alldata = Queue(alldata);
                system("CLS");
                ascii_mainMenu();
                printf("\n\n");
            }else if(input == '\x0D' && inputchoice == 3){
                system("CLS");
                alldata = callpatient(alldata);
                system("CLS");
                ascii_mainMenu();
                printf("\n\n");
            }else if(input == '\x0D' && inputchoice == 4){
                system("CLS");
                displaypharmacy();
                system("CLS");
                ascii_mainMenu();
                printf("\n\n");
            }else if(input == '\x0D' && inputchoice == 5){
                system("CLS");
                deletepharmacy();
                system("CLS");
                ascii_mainMenu();
                printf("\n\n");
            }else if(input == '\x0D' && inputchoice == 6){
                system("CLS");
                ascii_exiAnimated();
                exit(1);
            }

            for(int i = 0; i<7; i++){
                if(i != inputchoice){
                    printf("\t\t\t\t\t\t %s\n", logins[i]);
                }else{
                    printf("\t\t\t\t\t\t %s> %s <%s\n", CLR_PURP, logins[inputchoice], CLR_WHT);
                }
            }
        }


    }

    return 0;
}
