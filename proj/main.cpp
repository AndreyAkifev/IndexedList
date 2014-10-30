#include <iostream>
#include "Collection.h"
int main(){
	setlocale(LC_ALL, "Russian");
	Collection<int> *arr = NULL;
	while (true){
		std::cout << std::endl << "1. Создать список" << std::endl;
		std::cout << "2. Очистить список" << std::endl;
		std::cout << "3 Проверить список на пустоту" << std::endl;
		std::cout << "4. Опрос наличия заданного значения" << std::endl;
		std::cout << "5. Получить элемент по номеру" << std::endl;
		std::cout << "6. Изменить значение по заданному номеру" << std::endl;
		std::cout << "7. Получение позиции в списке с заданым значением" << std::endl;
		std::cout << "8. Добавить новое значение" << std::endl;
		std::cout << "9. Добавить новое значение в заданную позицию" << std::endl;
		std::cout << "10. Удаление заданного значения из списка" << std::endl;
		std::cout << "11. Удаление значения из позиции с заданным номером" << std::endl;
		std::cout << "0 - Выход из программы" << std::endl;
		std::cout << "Выберите действие:" << std::endl;
		int key = NULL;
		std::cin >> key;
		switch (key){
			case 1:
				std::cout << "Введите размер списка" << std::endl;
				std::cin >> key;
				arr = new Collection<int>(key);
				std::cout << "Создан список" << std::endl;
				system("pause");
			break;
			case 2:
				if (arr != NULL){
				arr->clear();
				std::cout << "Список очищен" << std::endl;
				}
				else{
				std::cout << "Список не создан" << std::endl;
				}
				system("pause");
			break;
			case 3:
				if (arr != NULL){
				arr->isEmpty() ? std::cout << "Список пуст" << std::endl : std::cout << "Список не пуст" << std::endl;

				}
				else{
				std::cout << "Список не создан" << std::endl;
				}
				system("pause");
			break;
			case 4:
				if (arr != NULL){
				std::cout << "Введите значение" << std::endl;
				std::cin >> key;
				arr->contains(key) ? std::cout << "Список содержит данное значение" << std::endl : std::cout << "Список не содержит данное значение" << std::endl;
				}
				else{
				std::cout << "Список не создан" << std::endl;
				};
				system("pause");
			break;
			case 5:
				if (arr != NULL){
					std::cout << "Введите номер элемента" << std::endl;
					std::cin >> key;
						if (arr->select(key) != NULL ){
							std::cout << "Значение выбранного элемента: " << arr->select(key) << std::endl;
						}
						else{
							std::cout << "Элемент не задан" << std::endl;
						};
				}
				else{
					std::cout << "Список не создан" << std::endl;
				};
				system("pause");
			break;
			case 6:
				if (arr != NULL){
					std::cout << "Введите номер позиции" << std::endl;
					std::cin >> key;
					std::cout << "Введите значение" << std::endl;
					int value;
					std::cin >> value;
					arr->update(value, key) ? std::cout << "Значение успешно добавлено" << std::endl : std::cout << "Ошибка: размер списка не соответствует номеру позиции" << std::endl;
				}
				else{
					std::cout << "Список не создан" << std::endl;
				}
					system("pause");
			break;
			case 7:
				if (arr != NULL){
					std::cout << "Введите значение" << std::endl;
					std::cin >> key;
					key = arr->search(key);
					if (key != -1){
						std::cout << "Заданное значение имеет позицию: " << key << std::endl;
					}
					else{
						std::cout << "Заданного значения нет в списке" << std::endl;
					}
				}
				else{
					std::cout << "Список не создан" << std::endl;
				};
				system("pause");
			break;
			case 8:
				if (arr != NULL){
					std::cout << "Введите значение" << std::endl;
					std::cin >> key;
					arr->add(key) ? std::cout << "Значение добавлено" << std::endl : std::cout << "Ошибка: список полон" << std::endl;
				}
				else{
					std::cout << "Список не создан" << std::endl;
				}
				system("pause");
			break;
			case 9:
				if (arr != NULL){
					std::cout << "Введите номер позиции" << std::endl;
					std::cin >> key;
					int value;
					std::cout << "Введите значение" << std::endl;
					std::cin >> value;
					arr->insert(value, key) ? std::cout << "Значение добавлено" << std::endl : std::cout << "Ошибка: добавление значения вызвет переполнение списка" << std::endl;
				}
				else{
					std::cout << "Список не создан" << std::endl;
				}
				system("pause");
			break;
			case 10:
				if (arr != NULL){
					std::cout << "Введите значение для удаления" << std::endl;
					std::cin >> key;
					arr->deleteValue(key) ? std::cout << "Значение удалено" << std::endl : std::cout << "Такого значение в списке нет" << std::endl;
				}
				else{
				std::cout << "Список не создан" << std::endl;
				}
				system("pause");
			break;
			case 11:
				if (arr != NULL){
					std::cout << "Введите номер удаляемого значения" << std::endl;
					std::cin >> key;
					arr->deleteValue(key) ? std::cout << "Значение удалено" << std::endl : std::cout << "Ошибка: размер списка не соответстует номеру удаляемого элемента" << std::endl;
			}
			else{
				std::cout << "Список не создан" << std::endl;
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

