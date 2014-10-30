
template <class T> class Collection{

	friend class Iterator;

	int *next;
	T	*value;
	int *prev;
	int head;
	int free;
	int tmpInsert;
	int last;
	int capacity;
	int size;

public:
	Collection(int);
	Collection(const Collection<T> & anotherCollection);
	bool insert(T, int);
	bool add(T);
	T    select(int);
	int  getSize();
	bool isEmpty();
	bool update(T, int);
	int  search(T);
	void clear();
	bool deleteValue(T);
	bool deleteId(int);
	bool contains(T);

	void debug();
	~Collection();

	class Iterator{

		Collection *ptr;
		int id;
		T object;
	public:
		Iterator(Collection *list){
			ptr = list;
			id = -1;
		};
		bool begin(){
			if (ptr->size > 0){
				id = 0;
				object = ptr->select(id);
				return true;
			} return false;
		};
		bool end(){
			if (ptr->size > 0){
				id = ptr->size - 1;
				object = ptr->select(id);
				return true;
			} return false;
		};
		bool next(){
			if (id != -1){
				id++;
				if (isOff()) return false;
				object = ptr->select(id);
				return true;
			}return false;
		};
		bool prev(){
			if (id != -1){
				id--;
				if (isOff()) return false;
				object = ptr->select(id);
				return true;
			}return false;
		};
		bool isOff(){ //конец массива
			if (ptr->size - 1 < id || id < 0){
				return true;
			}
			return false;
		};
		T& operator *(){
			return object;
		};
	};


};



template <typename T>
Collection<T>::Collection(int num){

	if (num > 0){
		next = new int[num];
		value = new T[num];
		prev = new int[num];

		next[0] = -1;
		next[num - 1] = -1;
		prev[0] = -1;
		head = -1;
		free = 0;
		last = 0;
		tmpInsert = -1;
		size = 0;
		capacity = num;

		for (int i = 0; i < num - 1; i++){
			next[i] = i + 1;
			prev[i] = i - 1;
		}

	}
	else std::cout << "Error in constructor";

};

template <typename T>
Collection<T>::Collection(const Collection<T> & anotherCollection){
	if (anotherCollection.size > 0){
		capacity = anotherCollection.capacity;
		next = new int[capacity];
		value = new T[capacity];
		prev = new int[capacity];

		for (int i = 0; i < anotherCollection.size; i++){
			next[i] = anotherCollection.next[i];
			value[i] = anotherCollection.value[i];
			prev[i] = anotherCollection.prev[i];
		}
		size = anotherCollection.size;
		head = anotherCollection.head;
		free = anotherCollection.free;
		last = anotherCollection.last;
		tmpInsert = anotherCollection.tmpInsert;
	}
};

template <typename T>
bool Collection<T>::insert(T obj, int id){
	if (capacity > size){

		value[free] = obj;
		int next_free = next[free];

		// если в списке что-то есть
		if (id < size && id >= 0){
			//если нужно записать на 1(0) место
			if (id == 0){
				next[free] = head;
				prev[head] = free;
				head = free;
				prev[free] = -1;
			}
			else {
				//если нужно записать в "середину" и конец списка
				//определ¤ем направление обхода спсика (prev or next)
				if (id < (int)size / 2){
					int tmp_next = head;

					for (int i = 1; i < id; i++){
						//перебор списка next
						tmp_next = next[tmp_next];
					}

					//мен¤ем местами prev ¤чейки соответсвующего id и ¤чейки free
					prev[free] = prev[next[tmp_next]];
					prev[next[tmp_next]] = free;

					//мен¤ем местами next ¤чейки соответсвующего id-1 и ¤чейки free
					next[free] = next[tmp_next];
					next[tmp_next] = free;
				}
				else {
					int tmp_prev = last;

					for (int i = 1; i < size - id; i++){
						//перебор списка prev
						tmp_prev = prev[tmp_prev];
					}

					//если конец списка
					if (id == size - 1){
						next[free] = tmp_prev;
						next[prev[tmp_prev]] = free;

						prev[free] = prev[tmp_prev];
						prev[tmp_prev] = free;

						last = tmp_prev;
					}
					else {
						//мен¤ем местами prev ¤чейки соответсвующего id и ¤чейки free
						prev[free] = prev[tmp_prev];
						prev[tmp_prev] = free;

						next[free] = next[tmp_prev];
						next[tmp_prev] = free;
					}
				}
			}

			size++;
			free = next_free;
			return true;
			//если список пусти запись в 1(0) позицию
		}
		else if (id == 0) {
			next[free] = -1;
			prev[free] = -1;
			head = free;
			free = next_free;
			size++;
			return true;
		}
		return false;
	}
	else return false;
};

template <typename T>
bool Collection<T>::add(T obj){
	if (capacity > size){
		value[free] = obj;
		if (free == 0 && head == -1) head = 0;

		if (tmpInsert != -1){
			prev[free] = tmpInsert;
			next[tmpInsert] = free;
		}

		tmpInsert = free;
		last = free;

		int cur = free;
		free = next[free];
		next[cur] = -1;
		size++;
		return true;
	}
	else return false;
};

template <typename T>
T Collection<T>::select(int id){
	if (id < size && id >= 0){
		if (id < (int)size / 2){
			int tmp_next = head;
			for (int i = 0; i < id; i++){
				tmp_next = next[tmp_next];
			}
			if (tmp_next >= 0)
				return value[tmp_next];
			else return NULL;
		}
		else {
			int tmp_prev = last;
			for (int i = 1; i < size - id; i++){
				tmp_prev = prev[tmp_prev];
			}
			if (tmp_prev >= 0)
				return value[tmp_prev];
			else return NULL;
		}
	}
	return NULL;
};

template <typename T>
int Collection<T>::getSize(){
	return size;
};

template <typename T>
bool Collection<T>::isEmpty(){
	if (size == 0) return true;
	else return false;
};

template <typename T>
bool Collection<T>::update(T obj, int id){
	if (size > 0 && id >= 0 && id < size){
		if (id < (int)size / 2){
			int tmp_next = head;
			for (int i = 0; i < id; i++){
				tmp_next = next[tmp_next];
			}
			if (tmp_next >= 0){
				value[tmp_next] = obj;
			}
		}
		else {
			int tmp_prev = last;
			for (int i = 1; i < size - id; i++){
				tmp_prev = prev[tmp_prev];
			}
			if (tmp_prev >= 0){
				value[tmp_prev] = obj;
			}
		}
		return true;

	} return false;
};

template <typename T>
int Collection<T>::search(T obj){
	if (size > 0){
		int tmp_next = head;
		for (int i = 0; i < size; i++){
			if (tmp_next >= 0){
				if (value[tmp_next] == obj){
					return tmp_next;
				}
			}
			tmp_next = next[tmp_next];
		}
	} return -1;
};


template <typename T>
void Collection<T>::clear(){
	next[0] = -1;
	next[capacity - 1] = -1;
	prev[0] = -1;
	head = -1;
	free = 0;
	last = 0;
	tmpInsert = -1;
	size = 0;

	for (int i = 0; i < capacity - 1; i++){
		next[i] = i + 1;
		prev[i] = i - 1;
	}
};

template <typename T>
bool Collection<T>::deleteValue(T obj){
	if (size > 0){
		int tmp_next = head;
		for (int i = 0; i < size; i++){
			if (tmp_next >= 0){
				if (value[tmp_next] == obj){
					//если удал¤ем 1(0) элемент
					if (i == 0){
						head = next[tmp_next];
						prev[next[tmp_next]] = -1;
						break;
					}
					else if (i == size - 1){//если удал¤ем последний элемент
						last = prev[tmp_next];
						break;
						//в остальных случа¤х
					}
					else {
						next[prev[tmp_next]] = next[tmp_next];
						prev[next[tmp_next]] = prev[tmp_next];
						break;
					}
				}
			}
			tmp_next = next[tmp_next];
		}
		next[tmp_next] = free;
		free = tmp_next;
		size--;

		//дл¤ отладки
		value[tmp_next] = -10;
		prev[tmp_next] = -10;
		return true;

	} return false;
};

template <typename T>
bool Collection<T>::deleteId(int id){
	if (size > 0 && id >= 0 && id < size){

		if (id < (int)size / 2){
			int tmp_next = head;
			for (int i = 0; i < id; i++){
				tmp_next = next[tmp_next];
			}
			if (tmp_next >= 0){
				//если удал¤ем 1(0) элемент
				if (id == 0){
					head = next[tmp_next];
					prev[next[tmp_next]] = -1;

					//в остальных случа¤х
				}
				else {
					next[prev[tmp_next]] = next[tmp_next];
					prev[next[tmp_next]] = prev[tmp_next];
				}
			}

			next[tmp_next] = free;
			free = tmp_next;
			size--;

			//дл¤ отладки
			value[tmp_next] = -10;
			prev[tmp_next] = -10;

		}
		else {
			int tmp_prev = last;
			for (int i = 1; i < size - id; i++){
				tmp_prev = prev[tmp_prev];
			}
			if (tmp_prev >= 0){
				if (id == size - 1){//если удал¤ем последний элемент
					last = prev[tmp_prev];
					//в остальных случа¤х
				}
				else {
					next[prev[tmp_prev]] = next[tmp_prev];
					prev[next[tmp_prev]] = prev[tmp_prev];
				}
			}

			next[tmp_prev] = free;
			free = tmp_prev;
			size--;

			//дл¤ отладки
			value[tmp_prev] = -10;
			prev[tmp_prev] = -10;

		}
		return true;

	}
	else return false;
};

template <typename T>
bool Collection<T>::contains(T obj){
	if (size > 0){
		int tmp_next = head;
		for (int i = 0; i < size; i++){
			if (tmp_next >= 0){
				if (value[tmp_next] == obj){
					return true;
				}
			}
			tmp_next = next[tmp_next];
		}
	} return false;
};

template <typename T>
Collection<T>::	~Collection(){
	if (next != nullptr) delete[]next;
	if (value != nullptr) delete[]value;
	if (prev != nullptr) delete[]prev;
};

template <typename T>
void Collection<T>::debug(){

	int tmp = size;

	std::cout << endl << endl;
	cout.width(3);

	std::cout << "index: ";
	for (int i = 0; i<tmp; i++){
		cout.width(3);
		std::cout << i << " ";
	}
	std::cout << endl;

	std::cout << "next:  ";
	for (int i = 0; i<tmp; i++){
		cout.width(3);
		std::cout << next[i] << " ";
	}
	std::cout << endl;

	std::cout << "val:   ";
	for (int i = 0; i<tmp; i++){
		cout.width(3);
		std::cout << value[i] << " ";
	}
	std::cout << endl;

	std::cout << "prev:  ";
	for (int i = 0; i<tmp; i++){
		cout.width(3);
		std::cout << prev[i] << " ";
	}
	std::cout << endl << endl;
};

