# Console-Chat v2
Вторая версия консольного чата. основные изменения – пароль теперь хранится в виде хеша, что делает его более защищенным. Переписаны пользовательские типы данных User и Chat. 

Консольный Чат позволяет выполнить вход/авторизацию по логину или паролю. В Чате можно отправлять сообщения либо в общий чат, где есть все пользователи, либо в приватный чат с конкретным пользователем.
Логины, хеши от паролей и никнеймы хранятся в файле AuthData.txt, сообщения разных чатов хранятся в отдельных файлах для того, чтобы при закрытии консоли данные не пропадали. При запуске консоли все данные с файлов считываются и запоминаются в контенйер inordered_map<string, User>, где ключом является логин пользователя, а значением объект пользовательского класса User. Затем в нескольких вложенных циклах while происходят последовательно авторизация/регистрация, выбор чата, отправка сообщения или закрытие чата. На каждом этапе предусмотрен выбор опций с помощью специального символа (например, выбор чата или выход из пользователя). Для каждого чата создается свой файл. Также отдельно создается файл для логинов, паролей и никнеймов.

## Зачем нужен Консольный Чат?
Главная цель данного проекта - освоение языка программирования C++, основных его конструкций, а также принципов ООП. Это начальная стадия проекта, которая в дальнейшем будет совершенствоваться.

## Пользовательские типы данных
Для реализации Консольного Чата созданы следующие пользователские типы данных:

* Chat

  Тип данных чата.

  1. Поля:
  	```
	- string _messages ← все сообщения чата.
	```
  2. Методы:
  	```
  	- void SetMessages(string message) ← добавление сообщений (функция нужна для считывания с файла инорфмации);
  	- void addMessage(string message, string username) ← добавление соообщения от конкретного пользователя;
  	- void clear() ← очистка сообщений.
	```
* User

  Тип данных пользователей.

  1. Поля:
  	```
  	- int _ID ← ID пользователя;
  	- string _username ← никнейм пользователя;
  	- uint* _pass_hash ← хеш от пароля пользователя;
  	- map<int, Chat*> _chats ← словарь чатов данного пользователя 
	(ключом является ID собеседника, значением - адрес (указатель) нужного чата);
	```
  2. Методы:
     2.1. Геттеры и сеттеры:
  	```
  	- void setName(string username);
   	- void setPassword(char* password, uint pass_length);
  	- void setPassword(string pass);
  	- void setPassword(uint* pass);
  	- void setID(int id);
  	- string getName() const;
  	- uint* getPassword() const;
  	- int getID() const;
  	- void set_chat(Chat* chat, int position) ← добавление указатель на чат в словарь чатов пользователя.
	```
  
	2.2. Дополнительный функционал:
  	```
  	- int get_chats_count() const ← выисление количества чатов;
  	- int get_receiver_id(int n) ← возвращает значение ID собеседника по порядковому номеру чата;
  	- void show_chat(int num) ← вывод сообщений чата с пользователем с ID = num на экран консоли;
  	- void add_message(string message, int num) ← добавление сообщения в чат от пользователя с ID = num;
 	- void erase() - очистка полей класса;
   	```	
