**Моделирование ДТП**
===============
![Modeling_ex](https://1.downloader.disk.yandex.ru/preview/6329548e96d1943780886b338f36db5263706fbd675e49dc3f6783794e179342/inf/e4yAmOpUdHfB_SQ08sGywY6RWpBdZTZ538chB57HiojmzNZ1ROP0K3sr0xEAeVKnbrwmFRqKUy-2uwGVyXgDlQ%3D%3D?uid=227757636&filename=1.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1280x825)
Данная программа предназначена для моделирования ДТП.
***
### **Функциональные возможности**

На данный момент программа позволяет моделировать столкновения двух и более автомобилей.
***
Основной целью программы(***Модели***), является определение конечного положения автомобилей, после их столкновения
***
![GUI_Modeling_ex](https://1.downloader.disk.yandex.ru/preview/5d1039273fab8b914aab0059256f0d0142fc5a92841ebe160231bd91a14876c6/inf/e4yAmOpUdHfB_SQ08sGywc2CX730zv9CQXkRoEITuVEArzK1wcC9_jHBXemtSpedCCtJY9au3z_E3VcYBkHDEw%3D%3D?uid=227757636&filename=2.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1280x825)
Программа позволяет:
* Задавать количество автомобилей.
* Задавать коэффициент трения поверхности "карты".
* Задавать силу тяжести (направлена вдоль вертикальной оси).
* Задавать частоту записи лога (раз во фрейм).
* Просматривать лог моделирования и результаты моделирования.
* Собственно запускать моделирование.
* Сохранять и загружать параметры модели.
* Настраивать положение камеры и направление ее обзора
Для каждого автомобиля:
* Задавать координаты.
* Задавать азимут.
* Задавать массу корпуса и отдельно двигателя.
* Задавать скорость вдоль курса (выставленного азимута).
* Задавать параметр момента блокирования колес.
***
### ***Технические данные***
Разработка велась на ОС Lubuntu 16.04.2 32-bit.
Использовались библиотеки:
* [QT](https://www.qt.io/ru/)
* [Bullet Physics Library](http://bulletphysics.org/wordpress/)
* [OpenSceneGraph](http://www.openscenegraph.org/)
* [osgBullet](http://osgbullet.vesuite.org/)
***
Проект QTCreator, папка bin содержит собранный тестовый проект, в папке Resources содержатся текстуры и модели используемые в программе.



