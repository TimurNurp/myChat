Проект представляет собой консольное приложение, которое позволяет обмениваться сообщениями между пользователями в пределах одного ПК.

Приложение включает в себя:
  -Главное меню;
  -Меню регистрации;
  -Меню входа;
  -Меню профиля пользователя;
  -Меню отправки сообщений;
  -Меню просмотра входящих сообщений;
  -Меню настроек пользователя.


Описание логики ГЛАВНОГО МЕНЮ

При запуске приложения в консоль выводится ГЛАВНОЕ МЕНЮ и предлагается выбрать пользователю следующее действие. 
Выбор пользователь осуществляет вводом соотв. цифры меню и вводом ее в консоле.
В ГЛАВНОЕ МЕНЮ входят следующие пункты:
  1. Вход - переводит пользователя в МЕНЮ ВХОДА;
  2. Регистрация - переводит пользователя в МЕНЮ РЕГИСТРАЦИИ;
  3. Выход - закрывает консольное приложение.


Описание логики МЕНЮ РЕГИСТРАЦИЯ

При переходе в МЕНЮ РЕГИСТРАЦИЯ пользователю предлагается ввести логин. После ввода логина следует проверка введеных символов на совпадения в массиве пользователей.
Если такой логин уже есть то выводится на экран предупреждение и предлаегается повторить ввод логина. После успешного ввода логина, пользователю предлагается ввести пароль, 
потом имя пользователя.
После успешной регистрации пользователю выводиться меню профиля пользователя.


Описание логики МЕНЮ ВХОДА

При перходе в МЕНЮ ВХОДА пользователю предлагается ввести логин. После ввода логина следует проверка введеных символов на совпадения в массиве пользователей.
Если такого логина нет, то пользователя переводит в меню регистрации. После успешного ввода логина, пользователю предлагается ввести пароль. Если пароль не совпадает
пользователю выводится предупреждение и предлагается повторить ввод.
После проверки данных пользователю выводиться меню профиля пользователя.


Описание логики МЕНЮ ПРОФИЛЯ ПОЛЬЗОВАТЕЛЯ

При переходе в меню на консоль выводится содержание МЕНЮ ПРОФИЛЯ ПОЛЬЗОВАТЕЛЯ и предлагается выбрать пользователю следующее действие. 
Выбор пользователь осуществляет вводом соотв. цифры меню и вводом ее в консоле.
В МЕНЮ ПРОФИЛЯ ПОЛЬЗОВАТЕЛЯ входят следующие пункты:
  1. Отправка сообщений - переводит пользователя в ОТПРАВИКИ СООБЩЕНИЙ;
  2. Просмотр входящих сообщений - переводит пользователя в МЕНЮ ПРОСМОТРА ВХОДЯЩИХ СООБЩЕНИЙ;
  3. Сменить статус - Выводи пользователю его текущий статус и предлает изменить его;
  4. Настройки - переводит пользователя в МЕНЮ НАСТРОЙКИ;
  5. Выход из профиля - переводит пользователя в ГЛАВНОЕ МЕНЮ;
  6. Выход - закрывает консольное приложение.


Описание логики МЕНЮ ОТПРАВИКИ СООБЩЕНИЙ

При переходе в данное меню на консоль выводится список доступных пользователей кому можно написать сообщение.


