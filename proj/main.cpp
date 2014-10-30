#include <iostream>
#include "Collection.h"
int main(){
	setlocale(LC_ALL, "Russian");
	Collection<int> *arr = NULL;
	while (true){
		std::cout << std::endl << "1. ������� ������" << std::endl;
		std::cout << "2. �������� ������" << std::endl;
		std::cout << "3 ��������� ������ �� �������" << std::endl;
		std::cout << "4. ����� ������� ��������� ��������" << std::endl;
		std::cout << "5. �������� ������� �� ������" << std::endl;
		std::cout << "6. �������� �������� �� ��������� ������" << std::endl;
		std::cout << "7. ��������� ������� � ������ � ������� ���������" << std::endl;
		std::cout << "8. �������� ����� ��������" << std::endl;
		std::cout << "9. �������� ����� �������� � �������� �������" << std::endl;
		std::cout << "10. �������� ��������� �������� �� ������" << std::endl;
		std::cout << "11. �������� �������� �� ������� � �������� �������" << std::endl;
		std::cout << "0 - ����� �� ���������" << std::endl;
		std::cout << "�������� ��������:" << std::endl;
		int key = NULL;
		std::cin >> key;
		switch (key){
			case 1:
				std::cout << "������� ������ ������" << std::endl;
				std::cin >> key;
				arr = new Collection<int>(key);
				std::cout << "������ ������" << std::endl;
				system("pause");
			break;
			case 2:
				if (arr != NULL){
				arr->clear();
				std::cout << "������ ������" << std::endl;
				}
				else{
				std::cout << "������ �� ������" << std::endl;
				}
				system("pause");
			break;
			case 3:
				if (arr != NULL){
				arr->isEmpty() ? std::cout << "������ ����" << std::endl : std::cout << "������ �� ����" << std::endl;

				}
				else{
				std::cout << "������ �� ������" << std::endl;
				}
				system("pause");
			break;
			case 4:
				if (arr != NULL){
				std::cout << "������� ��������" << std::endl;
				std::cin >> key;
				arr->contains(key) ? std::cout << "������ �������� ������ ��������" << std::endl : std::cout << "������ �� �������� ������ ��������" << std::endl;
				}
				else{
				std::cout << "������ �� ������" << std::endl;
				};
				system("pause");
			break;
			case 5:
				if (arr != NULL){
					std::cout << "������� ����� ��������" << std::endl;
					std::cin >> key;
						if (arr->select(key) != NULL ){
							std::cout << "�������� ���������� ��������: " << arr->select(key) << std::endl;
						}
						else{
							std::cout << "������� �� �����" << std::endl;
						};
				}
				else{
					std::cout << "������ �� ������" << std::endl;
				};
				system("pause");
			break;
			case 6:
				if (arr != NULL){
					std::cout << "������� ����� �������" << std::endl;
					std::cin >> key;
					std::cout << "������� ��������" << std::endl;
					int value;
					std::cin >> value;
					arr->update(value, key) ? std::cout << "�������� ������� ���������" << std::endl : std::cout << "������: ������ ������ �� ������������� ������ �������" << std::endl;
				}
				else{
					std::cout << "������ �� ������" << std::endl;
				}
					system("pause");
			break;
			case 7:
				if (arr != NULL){
					std::cout << "������� ��������" << std::endl;
					std::cin >> key;
					key = arr->search(key);
					if (key != -1){
						std::cout << "�������� �������� ����� �������: " << key << std::endl;
					}
					else{
						std::cout << "��������� �������� ��� � ������" << std::endl;
					}
				}
				else{
					std::cout << "������ �� ������" << std::endl;
				};
				system("pause");
			break;
			case 8:
				if (arr != NULL){
					std::cout << "������� ��������" << std::endl;
					std::cin >> key;
					arr->add(key) ? std::cout << "�������� ���������" << std::endl : std::cout << "������: ������ �����" << std::endl;
				}
				else{
					std::cout << "������ �� ������" << std::endl;
				}
				system("pause");
			break;
			case 9:
				if (arr != NULL){
					std::cout << "������� ����� �������" << std::endl;
					std::cin >> key;
					int value;
					std::cout << "������� ��������" << std::endl;
					std::cin >> value;
					arr->insert(value, key) ? std::cout << "�������� ���������" << std::endl : std::cout << "������: ���������� �������� ������ ������������ ������" << std::endl;
				}
				else{
					std::cout << "������ �� ������" << std::endl;
				}
				system("pause");
			break;
			case 10:
				if (arr != NULL){
					std::cout << "������� �������� ��� ��������" << std::endl;
					std::cin >> key;
					arr->deleteValue(key) ? std::cout << "�������� �������" << std::endl : std::cout << "������ �������� � ������ ���" << std::endl;
				}
				else{
				std::cout << "������ �� ������" << std::endl;
				}
				system("pause");
			break;
			case 11:
				if (arr != NULL){
					std::cout << "������� ����� ���������� ��������" << std::endl;
					std::cin >> key;
					arr->deleteValue(key) ? std::cout << "�������� �������" << std::endl : std::cout << "������: ������ ������ �� ������������ ������ ���������� ��������" << std::endl;
			}
			else{
				std::cout << "������ �� ������" << std::endl;
			}
			system("pause");
			break;
		default:
			exit(0);
		break;
		}
	};
	return 0;
}

