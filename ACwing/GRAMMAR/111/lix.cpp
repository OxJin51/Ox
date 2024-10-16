/*
 * Created by LixWorth on 2024/02/04 16:56
 * Github: https://github.com/lixworth/
 * Website: https://blog.lix.moe/
 * Contact: lixworth@outlook.com
**/
// C���ԣ�ʹ���������һ��ѧ������ϵͳ��
// Ҫ��������ѧ�����ݣ�ɾ��ѧ�����ݣ�
// ����ָ��ѧ������ʾȫ�����ݣ�����ȫ��ѧ�����ݵ��ļ������Ҷ�������ʱ���ᶪʧ������Ϣ
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
        std::cout << "����ѧ������\n";
        return;
    }

    while (list != nullptr) {
        std::cout << "ѧ��ID:" << list->uid << " ����:" << list->name << " �Ա�:";
        if (list->gender == MALE) {
            std::cout << "��\n";
        } else if (list->gender == FEMALE) {
            std::cout << "Ů\n";
        } else {
            std::cout << "δ֪?\n";
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

    std::cout << "����������:";
    std::cin >> name;
    std::cout << "�������Ա�(��:1,Ů:2):";
    std::cin >> gender;

    addStuFun(0, gender, name);

    SUCCESS << "����ɹ�\n";
}

void deleteStu() {
    if (stuNode0 == nullptr) {
        std::cout << "���ڿ���û���κ�ѧ����Ϣ\n";
        return;
    }
    int id;
    std::cout << "��������Ҫɾ��ѧ����ID:";
    std::cin >> id;
    if (stuNode0->uid == id) {
        Student *tmp = stuNode0;
        stuNode0 = stuNode0->next;
        delete tmp;
        std::cout << "ɾ���ɹ�\n";
        return;
    } else {
        Student *del = stuNode0->next;
        Student *before = stuNode0;
        while (del != nullptr) {
            if (del->uid == id) {
                before->next = del->next;
                delete del;
                std::cout << "ɾ���ɹ�\n";
                return;
            }
            before = del;
            del = del->next;
        }
    }
    std::cout << "δ�ҵ�ָ��ѧ�����ݣ�ɾ��ʧ�ܣ�" << std::endl;
}

void searchStu() {
    if (stuNode0 == nullptr) {
        std::cout << "���ڿ���û���κ�ѧ����Ϣ\n";
        return;
    }
    int id;
    std::cout << "��������Ҫ����ѧ����ID:(���������������˾�������)";
    std::cin >> id;

    Student *find = stuNode0;

    if(stuNode0->uid == id){
        std::cout << "ѧ��ID:" << find->uid << " ����:" << find->name << " �Ա�:";
        if (find->gender == MALE) {
            std::cout << "��\n";
        } else if (find->gender == FEMALE) {
            std::cout << "Ů\n";
        } else {
            std::cout << "δ֪?\n";
        }
        return;
    }
    while (find->next != nullptr) {
        if (find->uid == id) {
            std::cout << "ѧ��ID:" << find->uid << " ����:" << find->name << " �Ա�:";
            if (find->gender == MALE) {
                std::cout << "��\n";
            } else if (find->gender == FEMALE) {
                std::cout << "Ů\n";
            } else {
                std::cout << "δ֪?\n";
            }
            return;
        }
        find = find->next;
    }
    std::cout << "δ�ҵ�ָ��ѧ����Ϣ" << std::endl;
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
        ERROR << "����ʧ�ܣ�����Ŀ¼û��Ȩ��д���ļ���\n";
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
        ERROR << "����ʧ�ܣ�����Ŀ¼û��Ȩ��д���ļ���\n";
    }
    data_file.close();
}

void menu() {
    LOG_CLEAR;
    std::cout << "ѧ������ϵͳ\n����: LixWorth<lixworth@outlook.com>\n";
    time_t now = time(0);
    struct tm *local = localtime(&now);

    printf("���ڵ�ʱ����: %d/%02d/%02d %02d:%02d:%02d\n\n�˵�:\n",
           1900 + local->tm_year, 1 + local->tm_mon, local->tm_mday,
           local->tm_hour, local->tm_min, local->tm_sec);
    WARN << "1.���ȫ��ѧ���б�" << std::endl;
    WARN << "2.���һ��ѧ��" << std::endl;
    WARN << "3.ɾ��һ��ѧ��" << std::endl;
    WARN << "4.����һ��ѧ��" << std::endl;
    WARN << "5.�˳�������" << std::endl;

    INFO << std::endl << "������˵����(1-4): ";
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
                    ERROR << "�˵�����: ������������Ժ���̽����!" << "\n";
                    SEND_PAUSE;
                    break;
            }
        } else {
            LOG_CLEAR;
            std::cout << input << std::endl;
            ERROR << "���������ֽ��в˵�����Ŷ\n";
            SEND_PAUSE;
        }
    }
    saveStu();
    return 0;
}