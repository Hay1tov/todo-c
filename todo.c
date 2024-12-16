#include <stdio.h>
#include <string.h>

typedef struct {
    char title[128];
    char description[512];
    int status;
} Task;

Task tasks[100]; 
int count = 0;    
int exit = 1;

void add_task(){

    char arr_title[128], arr_description[512];
    printf("Vazifa kiriting kiriting :");
    
    fgets(arr_title, sizeof(arr_title), stdin);

    for (int i = 0; arr_title[i + 1] != '\0'; i++){

        tasks[count].title[i] = arr_title[i];
    }

    printf("Kiritgan vazifangizga tavsif bering :");

    fgets(arr_description, sizeof(arr_description), stdin);
    for (int i = 0; arr_description[i + 1] != '\0'; i++){

        tasks[count].description[i] = arr_description[i];
    }
    tasks[count].status = 0;

    count++;
};

void list_all_tasks(){
    if(count == 0){
        printf("Buyruqlar mavjud emas. Iltimos avval buyruq kiriting\n");
    }else
    {
        printf("ID | Title       | Description              | Status\n----------------------------------------------------------\n");
        for (int i = 0; i < count; i++)
        {
            if (tasks[i].status != -1) 
            {
                printf("%-3d", i + 1);
                printf("| %-12s", tasks[i].title);
                printf("| %-25s", tasks[i].description);
                if (tasks[i].status == 0){

                    printf("| Bajarilmagan\n");
                }
                else
                    printf("| Bajarilgan\n");
            }   
        }  
    }   
};

void get_task_by_id(){

    int total, deleted_index;

    printf("Izlazyotgan vazifangizning ID raqamini kiriting: "); scanf("%d", &total);

    deleted_index = tasks[total - 1].status;
    if ((total - 1 <= count) && (count != 0) && deleted_index != -1){

        printf("%-3d", total);

        printf("| %-12s", tasks[total - 1].title);

        printf("| %-25s", tasks[total - 1].description);

        if (tasks[total - 1].status == 0){

            printf("| Bajarilmagan\n");
        }
        else
            printf("| Bajarilgan\n");
    }
    else {
        printf("Vazifa mawjud emas ");
    }
    
    
};

void delete_task_by_id(){
    int total;

    printf("O`chirmoqchi bo`lgan vazifangixni ID raqamini kiriting: "); scanf("%d", &total);
    if ((total - 1 <= count) && (count != 0)){

        if (tasks[total - 1].status != -1){

            tasks[total - 1].status = -1;
            printf("Vazifa muofaqqiyatli o'chirildi!\n");
        }
        else {
            printf("Bu ID avval o'chirilgan");
        }
        
        
    }
    else {
        printf("Bu ID ga vazifa kiritilmagan!\nIltimos boshqa ID kiriting: ");
    }
    
    };

void mark_task_completed(){

    int total;
    printf("Bajarilgan vazifani ni ID raqamini kiriting: "); scanf("%d", &total);

    if (total - 1 <= count && count != 0){
        while (tasks[total - 1].status == 1){
            printf("Bu vazifa bajarilgan!\nIltimos, boshqa vazifa ID sini kiriting: ");
            scanf("%d", &total);
        }
        tasks[total - 1].status = 1;
        printf("Vazifa bajarildi deb kiritildi :)\n");
    }else {
        printf("Bu ID da vazifa mavjud emas, iltimos boshqa ID ni kiriting!\n");
    }    
};

void mark_task_incomplete(){

    int total;
    printf("Bajarilmagan vazifaning ID raqamini kiriting: "); scanf("%d", &total);

    if (total - 1 <= count && count != 0){

        while (tasks[total - 1].status == 0){

            printf("Bu vazifa avval bajarilmagan!\nBoshqa vazifa ID  kiriting: ");
            scanf("%d", &total);
        }

        tasks[total - 1].status = 0;
        printf("Vazifa bajarilmadi deb kiritildi :(\n");
    }
    else {
            printf("Ushbu ID vazifa mavjud emas, Boshqa ID ni kiriting!\n");
        }
    };

void show_menu(void){

printf("To-Do List Menu:\n-------------------------\n1. Add Task\n2. List Tasks\n3. Get Task by ID\n4. Delete Task\n5. Mark Task as Completed\n6. Mark Task as Incompleted\n7-Menu ga qaytish \n8. Exit\n-------------------------\n");
}

int main(){

    printf("To-Do List Menu:\n-------------------------\n1. Add Task\n2. List Tasks\n3. Get Task by ID\n4. Delete Task\n5. Mark Task as Completed\n6. Mark Task as Incompleted\n7. Menu ga qaytish\n8. Exit\n-------------------------\n");
    
    while (exit != 8)
    {  
        printf("\n-------------------------\nMenyu tanlang: ");
        scanf("%d", &exit);
        while (getchar() != '\n')
            ;
        switch (exit){
        case 1:
            add_task();
            break;
        case 2:
            list_all_tasks();
            break;
         case 3:
             get_task_by_id();
             break;
        case 4:
            delete_task_by_id();
            break;
        case 5:
            mark_task_completed();
            break;
        case 6:
            mark_task_incomplete();
            break;
         case 7:
             show_menu();
             break;
         case 8:
             break;
        
         default:
             printf("Siz tanlagan menu mavjud emas.\n Ro'yxatda berilgan menyu lardan birini tanlang: ");
             break;
        }
    }
}