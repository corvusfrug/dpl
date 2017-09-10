# **Моделирование ДТП** 
************
![Modeling_ex](https://3.downloader.disk.yandex.ru/preview/53c7124a9d241a7517f7ffc717f8affc623f2913e0455b09a8c40a373baaa67a/inf/e4yAmOpUdHfB_SQ08sGywY6RWpBdZTZ538chB57HiojmzNZ1ROP0K3sr0xEAeVKnbrwmFRqKUy-2uwGVyXgDlQ%3D%3D?uid=0&filename=1.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1165x786)
<img src="https://s57e.storage.yandex.net/rdisk/445685aa1bf9ebf181d109f7f0924a1e453643e87099476f429b174a03449c2b/59b54431/e4yAmOpUdHfB_SQ08sGywfY4bBIBtpJIL-4NOvkN7ThG3g5CevMQqhmV6GOWzH4qoaoxdTOMDl2nUWlj9J_DXw==?uid=227757636&filename=3.gif&disposition=inline&hash=&limit=0&content_type=image%2Fgif&fsize=3305161&hid=5c988b672102110b8b9fd5c9f9185837&media_type=image&tknv=v2&etag=55552f167e163ea9a0d5ccd8da1b9650&rtoken=jRDdM4aeJcN6&force_default=yes&ycrid=na-7a97cb280f56791675a7531b2b0fd409-downloader2e&ts=558d627c4ae40&s=4e44bb57268dd287e9fd68dd4a50d23c5aaafdbf61f67311d2188061afbd1b37&pb=U2FsdGVkX1907oA87uNEagh9hAiHD_7Ul6ADBWEc24OWBnxWhOjv5jps694sri7RIze8AJGVAJ3RA40Fp9UsWwYVx-trY58Vmbd9FAoLsAc=" width="510" height="394"/>
*************
Данная программа предназначена для моделирования ДТП.
*********
### ***Функциональные возможности***

На данный момент программа позволяет моделировать столкновения двух и более автомобилей.
**********
Основной целью программы(***Модели***), является определение конечного положения автомобилей, после их столкновения
*********
![GUI_Modeling_ex](https://1.downloader.disk.yandex.ru/preview/1045ae80d56a9f9bd9cf463c736f5bc3bcb28205622cc25a0a15ed0234e66876/inf/e4yAmOpUdHfB_SQ08sGywc2CX730zv9CQXkRoEITuVEArzK1wcC9_jHBXemtSpedCCtJY9au3z_E3VcYBkHDEw%3D%3D?uid=0&filename=2.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1165x786)
<img src="https://s61h.storage.yandex.net/rdisk/c4cf56f24a69fea9e7902b4c580c7de3c2f27e3155e5066fc26de038429fe306/59afd09b/e4yAmOpUdHfB_SQ08sGywXw9MGz52L5W1fUTXNk7tL4uXwXCCpovvzP4aqdVfawyG8NLoD_M6O_ble7u0IqAiA==?uid=227757636&filename=testCrash.gif&disposition=inline&hash=&limit=0&content_type=image%2Fgif&fsize=4200013&hid=d3f9038fcd59546809e8438118c3959b&media_type=image&tknv=v2&etag=434588a9932383579abd10c258d34f8d&rtoken=B8211SCCOyBi&force_default=yes&ycrid=na-9f686e2bdf65ace751eec2c078d5ede8-downloader7h&ts=55882f8d11cc0&s=4c7141c7e36d7c7c5bdb82b8d31b58100a520a2cf1512764b02717e1b7d863a0&pb=U2FsdGVkX1_8UGPA00N3ELWpcbTN5Bu041xxG9ELZB50CwwbppqZPsE0ZFY1znLPfJ-5I96u_AD8bGCJ1JOnOZxAcFrdSfSlpEm_P4IxzVg=" width="1165" height="400" align="center"/>

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

