# **Моделирование ДТП**
************
![Modeling_ex](https://3.downloader.disk.yandex.ru/preview/53c7124a9d241a7517f7ffc717f8affc623f2913e0455b09a8c40a373baaa67a/inf/e4yAmOpUdHfB_SQ08sGywY6RWpBdZTZ538chB57HiojmzNZ1ROP0K3sr0xEAeVKnbrwmFRqKUy-2uwGVyXgDlQ%3D%3D?uid=0&filename=1.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1165x786)
<img src="https://s57e.storage.yandex.net/rdisk/c88f11eff608c9a9a9307080987259e7194388e698ed33526596254366211d5a/59a32de8/e4yAmOpUdHfB_SQ08sGywfY4bBIBtpJIL-4NOvkN7ThG3g5CevMQqhmV6GOWzH4qoaoxdTOMDl2nUWlj9J_DXw==?uid=227757636&filename=3.gif&disposition=inline&hash=&limit=0&content_type=image%2Fgif&fsize=3305161&hid=5c988b672102110b8b9fd5c9f9185837&media_type=image&tknv=v2&etag=55552f167e163ea9a0d5ccd8da1b9650&rtoken=7QM1A060764P&force_default=yes&ycrid=na-97aa3b852adf9580024145332238d2b1-downloader2f&ts=557c22b394a00&s=8c7dc6d5c9ec59c8839b9ce9c5c6f2a550ac8739bf815964aafdfbc417110612&pb=U2FsdGVkX1-j3TCOvaSwTE-ilM6UOAgOmqpHJ114D2ZNH5ppxQDt7TPxwVb_ZjNvsKW2UC3zOvQIOvT-kj0U6pgnxO1WdJrHX7XxTzyBByg=" width="510" height="394"/>
*************
Данная программа предназначена для моделирования ДТП.
*********
### ***Функциональные возможности***

На данный момент программа позволяет моделировать столкновения двух и более автомобилей.
**********
Основной целью программы(***Модели***), является определение конечного положения автомобилей, после их столкновения
*********
![GUI_Modeling_ex](https://1.downloader.disk.yandex.ru/preview/1045ae80d56a9f9bd9cf463c736f5bc3bcb28205622cc25a0a15ed0234e66876/inf/e4yAmOpUdHfB_SQ08sGywc2CX730zv9CQXkRoEITuVEArzK1wcC9_jHBXemtSpedCCtJY9au3z_E3VcYBkHDEw%3D%3D?uid=0&filename=2.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1165x786)
<img src="https://s61h.storage.yandex.net/rdisk/39e85ddf71973e84e8fc2d9d4df45629fd44c10f334d8b6213c79f49add6f548/59a2fb16/e4yAmOpUdHfB_SQ08sGywXw9MGz52L5W1fUTXNk7tL4uXwXCCpovvzP4aqdVfawyG8NLoD_M6O_ble7u0IqAiA==?uid=227757636&filename=testCrash.gif&disposition=inline&hash=&limit=0&content_type=image%2Fgif&fsize=4200013&hid=d3f9038fcd59546809e8438118c3959b&media_type=image&tknv=v2&etag=434588a9932383579abd10c258d34f8d&rtoken=UZXkIkIhUE7D&force_default=yes&ycrid=na-40a6768e1409e90840ac18ebb836a804-downloader10h&ts=557bf23c47180&s=e5d3ecb08da3c62dc7a6dc5abae0bfbe0b16c9517e302624bb715a1980874af3&pb=U2FsdGVkX1-HtRE2_JWLnF2SAeGCQyV_d7dxulKY5PtB5JYD1bZbOqF6nUNpxNe595ae5MaOlLe8SPpyBeOGJejuBLeiXujzMeQqhL3f4SM=" width="1165" height="400" align="center"/>

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



