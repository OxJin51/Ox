/*
 * Created by LixWorth on 2024/02/04 16:56
 * Github: https://github.com/lixworth/
 * Website: https://blog.lix.moe/
 * Contact: lixworth@outlook.com
**/
// C语言，使用链表，完成一份学生管理系统，
// 要求能增加学生数据，删除学生数据，
// 查找指定学生，显示全部数据，保存全部学生数据到文件，并且二次运行时不会丢失数据信息
#include <bits/stdc++.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

#define INFO (std::cout << RESET)
#define WARN (std::cout << YELLOW)
#define ERROR (std::cout << RED)
#define SUCCESS (std::cout << GREEN)
#define LOG_CLEAR (std::cout << "\033c")

#define SEND_PAUSE (system("pause || read -p 'Press Enter to continue...' var"))
const std::string DATA_FILENAME = "students.txt";
enum gender_constant {
    UNKNOWN = 0,
    MALE = 1,
    FEMALE = 2
};
struct Student {
    int uid;
    std::string name;
    gender_constant gender;
    Student *next;
};

Student* stuNode0;

void listStu() {
    Student *list = stuNode0;

    if (list == nullptr) {
        std::cout << "暂无学生数据\n";
        return;
    }

    while (list != nullptr) {
        std::cout << "学生ID:" << list->uid << " 姓名:" << list->name << " 性别:";
        if (list->gender == MALE) {
            std::cout << "男\n";
        } else if (list->gender == FEMALE) {
            std::cout << "女\n";
        } else {
            std::cout << "未知?\n";
        }
        list = list->next;
    }
}

void addStuFun(int uid,int gender,std::string name) {
    Student *newStu = new Student;

    if (gender == MALE) {
        newStu->gender = MALE;
    } else if (gender == FEMALE) {
        newStu->gender = FEMALE;
    } else {
        newStu->gender = UNKNOWN;
    }
    newStu->name = name;
    if (stuNode0 == nullptr) {
        if (uid == 0) {
            newStu->uid = 1;
        } else {
            newStu->uid = uid;
        }
        stuNode0 = newStu;
    } else {
        Student *add = stuNode0;
        while (add->next != nullptr) {
            add = add->next;
        }
        if (uid == 0) {
            newStu->uid = add->uid + 1;
        } else {
            newStu->uid = uid;
        }
        add->next = newStu;
    }
}

void addStu() {
    int gender;
    std::string name;

    std::cout << "请输入姓名:";
    std::cin >> name;
    std::cout << "请输入性别(男:1,女:2):";
    std::cin >> gender;

    addStuFun(0, gender, name);

    SUCCESS << "保存成功\n";
}

void deleteStu() {
    if (stuNode0 == nullptr) {
        std::cout << "现在库里没有任何学生信息\n";
        return;
    }
    int id;
    std::cout << "请输入需要删除学生的ID:";
    std::cin >> id;
    if (stuNode0->uid == id) {
        Student *tmp = stuNode0;
        stuNode0 = stuNode0->next;
        delete tmp;
        std::cout << "删除成功\n";
        return;
    } else {
        Student *del = stuNode0->next;
        Student *before = stuNode0;
        while (del != nullptr) {
            if (del->uid == id) {
                before->next = del->next;
                delete del;
                std::cout << "删除成功\n";
                return;
            }
            before = del;
            del = del->next;
        }
    }
    std::cout << "未找到指定学生数据，删除失败！" << std::endl;
}

void searchStu() {
    if (stuNode0 == nullptr) {
        std::cout << "现在库里没有任何学生信息\n";
        return;
    }
    int id;
    std::cout << "请输入需要搜索学生的ID:(不想做搜索姓名了就这样吧)";
    std::cin >> id;

    Student *find = stuNode0;

    if(stuNode0->uid == id){
        std::cout << "学生ID:" << find->uid << " 姓名:" << find->name << " 性别:";
        if (find->gender == MALE) {
            std::cout << "男\n";
        } else if (find->gender == FEMALE) {
            std::cout << "女\n";
        } else {
            std::cout << "未知?\n";
        }
        return;
    }
    while (find->next != nullptr) {
        if (find->uid == id) {
            std::cout << "学生ID:" << find->uid << " 姓名:" << find->name << " 性别:";
            if (find->gender == MALE) {
                std::cout << "男\n";
            } else if (find->gender == FEMALE) {
                std::cout << "女\n";
            } else {
                std::cout << "未知?\n";
            }
            return;
        }
        find = find->next;
    }
    std::cout << "未找到指定学生信息" << std::endl;
}

void loadStu() {
    std::fstream data_file;
    data_file.open(DATA_FILENAME, std::ios::in);
    if (data_file.is_open()) {
        int uid, gender;
        std::string name;
        while (data_file >> uid >> gender >> name) {
            addStuFun(uid, gender, name);
        }
    } else {
        ERROR << "保存失败，可能目录没有权限写入文件！\n";
    }
    data_file.close();
}

void saveStu() {
    std::fstream data_file;
    data_file.open(DATA_FILENAME, std::ios::out | std::ios::trunc);
    if (data_file.is_open()) {
        Student *save = stuNode0;
        while (save != nullptr) {
            data_file << save->uid << " " << save->name << " " << save->gender << std::endl;
            save = save->next;
        }
    } else {
        ERROR << "保存失败，可能目录没有权限写入文件！\n";
    }
    data_file.close();
}

void menu() {
    LOG_CLEAR;
    std::cout << "学生管理系统\n作者: LixWorth<lixworth@outlook.com>\n";
    time_t now = time(0);
    struct tm *local = localtime(&now);

    printf("现在的时间是: %d/%02d/%02d %02d:%02d:%02d\n\n菜单:\n",
           1900 + local->tm_year, 1 + local->tm_mon, local->tm_mday,
           local->tm_hour, local->tm_min, local->tm_sec);
    WARN << "1.输出全体学生列表" << std::endl;
    WARN << "2.添加一个学生" << std::endl;
    WARN << "3.删除一个学生" << std::endl;
    WARN << "4.搜索一个学生" << std::endl;
    WARN << "5.退出并保存" << std::endl;

    INFO << std::endl << "请输入菜单编号(1-4): ";
}

int main() {
    bool run = true;
    loadStu();
    while (run) {
        menu();
        int input = getchar();
        if (input == 10) continue;
        if (input >= 48 && input <= 57) {
            switch (input) {
                case 49: // list
                    LOG_CLEAR;
                    listStu();
                    SEND_PAUSE;
                    break;
                case 50: // add
                    LOG_CLEAR;
                    addStu();
                    SEND_PAUSE;
                    break;
                case 51: // delete
                    LOG_CLEAR;
                    deleteStu();
                    SEND_PAUSE;
                    break;
                case 52: // search
                    LOG_CLEAR;
                    searchStu();
                    SEND_PAUSE;
                    break;
                case 53:
                    saveStu();
                    run = false;
                    break;
                default:
                    ERROR << "菜单错误: 后面的区域请以后再探索吧!" << "\n";
                    SEND_PAUSE;
                    break;
            }
        } else {
            LOG_CLEAR;
            std::cout << input << std::endl;
            ERROR << "请输入数字进行菜单操作哦\n";
            SEND_PAUSE;
        }
    }
    saveStu();
    return 0;
}