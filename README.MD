# **Моделирование ДТП** 
************
![Modeling_ex](https://3.downloader.disk.yandex.ru/preview/53c7124a9d241a7517f7ffc717f8affc623f2913e0455b09a8c40a373baaa67a/inf/e4yAmOpUdHfB_SQ08sGywY6RWpBdZTZ538chB57HiojmzNZ1ROP0K3sr0xEAeVKnbrwmFRqKUy-2uwGVyXgDlQ%3D%3D?uid=0&filename=1.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1165x786)
<img src="http://s019.radikal.ru/i640/1709/77/b213fcc85406.gif" width="510" height="394"/>
*************
Данная программа предназначена для моделирования ДТП.
*********
### ***Функциональные возможности***

На данный момент программа позволяет моделировать столкновения двух и более автомобилей.
**********
Основной целью программы(***Модели***), является определение конечного положения автомобилей, после их столкновения
*********
![GUI_Modeling_ex](https://1.downloader.disk.yandex.ru/preview/1045ae80d56a9f9bd9cf463c736f5bc3bcb28205622cc25a0a15ed0234e66876/inf/e4yAmOpUdHfB_SQ08sGywc2CX730zv9CQXkRoEITuVEArzK1wcC9_jHBXemtSpedCCtJY9au3z_E3VcYBkHDEw%3D%3D?uid=0&filename=2.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1165x786)
[URL=http://radikal.ru/fp/twmhw7l2kjeyr][IMG]http://s013.radikal.ru/i325/1709/fc/08d6f59ab8e3t.jpg[/IMG][/URL]

*********
Программа позволяет: 
********
+ Задавать количество автомобилей.
+ Задавать коэффициент трения поверхности "карты".
+ Задавать силу тяжести (направлена вдоль вертикальной оси).
+ Задавать частоту записи лога (раз во фрейм).
+ Просматривать лог моделирования и результаты моделирования.
+ Собственно запускать моделирование.
+ Сохранять и загружать параметры модели.
+ Настраивать положение камеры и направление ее обзора.
+ Для каждого автомобиля:
  + Задавать координаты.
  + Задавать азимут.
  + Задавать массу корпуса и отдельно двигателя.
  + Задавать скорость вдоль курса (выставленного азимута).
  + Задавать параметр момента блокирования колес.
********
### ***Технические данные***
Разработка велась на ОС [Lubuntu](http://lubuntu.me) 16.04.2 32-bit. 
Использовались библиотеки:
* [QT](https://www.qt.io/ru/)
* [Bullet Physics Library](http://bulletphysics.org/wordpress/)
* [OpenSceneGraph](http://www.openscenegraph.org/)
* [osgBullet](http://osgbullet.vesuite.org/)
*********
Проект QTCreator, папка bin содержит собранный тестовый проект, в папке Resources содержатся текстуры и модели используемые в программе.

