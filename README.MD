# **Моделирование ДТП**
************
![Modeling_ex](https://3.downloader.disk.yandex.ru/preview/53c7124a9d241a7517f7ffc717f8affc623f2913e0455b09a8c40a373baaa67a/inf/e4yAmOpUdHfB_SQ08sGywY6RWpBdZTZ538chB57HiojmzNZ1ROP0K3sr0xEAeVKnbrwmFRqKUy-2uwGVyXgDlQ%3D%3D?uid=0&filename=1.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1165x786)
<img src="https://s57e.storage.yandex.net/rdisk/a4f3928cf86f22fa0d556184e0fa99aba97976f58cef92978a124a2abb454766/5999fc14/e4yAmOpUdHfB_SQ08sGywfY4bBIBtpJIL-4NOvkN7ThG3g5CevMQqhmV6GOWzH4qoaoxdTOMDl2nUWlj9J_DXw==?uid=227757636&filename=3.gif&disposition=inline&hash=&limit=0&content_type=image%2Fgif&fsize=3305161&hid=5c988b672102110b8b9fd5c9f9185837&media_type=image&tknv=v2&etag=55552f167e163ea9a0d5ccd8da1b9650&rtoken=8FRkyRRKgU8w&force_default=yes&ycrid=na-eebc0ed199f29115fe41e9b4fbc41936-downloader1f&ts=55735dea82d00&s=7f47c2a8f2738bcd27199394502002928eb898ed9d0e1312013b76cab78f7ccd&pb=U2FsdGVkX19fCHMd2zZyVT11B0h0kKoo9guKyZ3Fn4BT7fDK0VBuCyo0raPcXU3gPBNoSWYxRfW6hlt6TdZicNnq-DtEHmeFdhfKK2NKRd0=" width="510" height="394"/>
*************
Данная программа предназначена для моделирования ДТП.
*********
### ***Функциональные возможности***

На данный момент программа позволяет моделировать столкновения двух и более автомобилей.
**********
Основной целью программы(***Модели***), является определение конечного положения автомобилей, после их столкновения
*********
![GUI_Modeling_ex](https://1.downloader.disk.yandex.ru/preview/1045ae80d56a9f9bd9cf463c736f5bc3bcb28205622cc25a0a15ed0234e66876/inf/e4yAmOpUdHfB_SQ08sGywc2CX730zv9CQXkRoEITuVEArzK1wcC9_jHBXemtSpedCCtJY9au3z_E3VcYBkHDEw%3D%3D?uid=0&filename=2.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1165x786)
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



