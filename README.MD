# **Моделирование ДТП**
************
![Modeling_ex](https://3.downloader.disk.yandex.ru/preview/53c7124a9d241a7517f7ffc717f8affc623f2913e0455b09a8c40a373baaa67a/inf/e4yAmOpUdHfB_SQ08sGywY6RWpBdZTZ538chB57HiojmzNZ1ROP0K3sr0xEAeVKnbrwmFRqKUy-2uwGVyXgDlQ%3D%3D?uid=0&filename=1.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1165x786)
<img src="https://s57e.storage.yandex.net/rdisk/18511b0f57cd8dd1ce7e8e82e8ba4238dbb32baeedd170559889a3a79f2f9e11/59adc6ed/e4yAmOpUdHfB_SQ08sGywfY4bBIBtpJIL-4NOvkN7ThG3g5CevMQqhmV6GOWzH4qoaoxdTOMDl2nUWlj9J_DXw==?uid=227757636&filename=3.gif&disposition=inline&hash=&limit=0&content_type=image%2Fgif&fsize=3305161&hid=5c988b672102110b8b9fd5c9f9185837&media_type=image&tknv=v2&etag=55552f167e163ea9a0d5ccd8da1b9650&rtoken=EZCr5XhhLqj3&force_default=yes&ycrid=na-b7609f219ce2b2a46d8e95fbe8e0ae79-downloader5f&ts=55863e09dd540&s=11973b6f745bb01910d3932c48ec8afcdee10dd2061d13215cdd372aafdc462c&pb=U2FsdGVkX18vCzEvPLeD7MOST7wb1DKhHulDISmbTSzgwHIbfOmHFlA2kqARYnlXWpn3RKtqNvOKBi18bI7ucSlatkmzgQRPB1vMV9orOG4=" width="510" height="394"/>
*************
Данная программа предназначена для моделирования ДТП.
*********
### ***Функциональные возможности***

На данный момент программа позволяет моделировать столкновения двух и более автомобилей.
**********
Основной целью программы(***Модели***), является определение конечного положения автомобилей, после их столкновения
*********
![GUI_Modeling_ex](https://1.downloader.disk.yandex.ru/preview/1045ae80d56a9f9bd9cf463c736f5bc3bcb28205622cc25a0a15ed0234e66876/inf/e4yAmOpUdHfB_SQ08sGywc2CX730zv9CQXkRoEITuVEArzK1wcC9_jHBXemtSpedCCtJY9au3z_E3VcYBkHDEw%3D%3D?uid=0&filename=2.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1165x786)
<img src="https://s56f.storage.yandex.net/rdisk/daeacb58bb0f807eae24384c577367ae75198d67ead24423904d81ecf8fd44cd/59adc706/e4yAmOpUdHfB_SQ08sGywXw9MGz52L5W1fUTXNk7tL4uXwXCCpovvzP4aqdVfawyG8NLoD_M6O_ble7u0IqAiA==?uid=227757636&filename=testCrash.gif&disposition=inline&hash=&limit=0&content_type=image%2Fgif&fsize=4200013&hid=d3f9038fcd59546809e8438118c3959b&media_type=image&tknv=v2&etag=434588a9932383579abd10c258d34f8d&rtoken=aJEqg3hBJxHz&force_default=yes&ycrid=na-ee85d9c8deb82fdef4084dfff56df47e-downloader5f&ts=55863e21b4d80&s=e0a1b8663fd8c2aca034c9a16f8f00ecd4a4f9e7577ed7762179dc6d0e5fc6cf&pb=U2FsdGVkX1-0uWXzSNaoZ4d9eHO5qz4oiIVTmf5eEeQOrKfIymjHl7YflGN5F8nIIorTrb-pw7GuaVoTQpddJZvGVFM3THmacHhf-OhE1_k=" width="1165" height="400" align="center"/>

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

