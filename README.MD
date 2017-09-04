# **Моделирование ДТП**
************
![Modeling_ex](https://3.downloader.disk.yandex.ru/preview/53c7124a9d241a7517f7ffc717f8affc623f2913e0455b09a8c40a373baaa67a/inf/e4yAmOpUdHfB_SQ08sGywY6RWpBdZTZ538chB57HiojmzNZ1ROP0K3sr0xEAeVKnbrwmFRqKUy-2uwGVyXgDlQ%3D%3D?uid=0&filename=1.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1165x786)
<img src="https://s210f.storage.yandex.net/rdisk/343f3021401dc4a2a5bf4db948430cbb5f19bd288fc96162215c0af724b7a9f3/59adc60f/e4yAmOpUdHfB_SQ08sGywfY4bBIBtpJIL-4NOvkN7ThG3g5CevMQqhmV6GOWzH4qoaoxdTOMDl2nUWlj9J_DXw==?uid=227757636&filename=3.gif&disposition=inline&hash=&limit=0&content_type=image%2Fgif&fsize=3305161&hid=5c988b672102110b8b9fd5c9f9185837&media_type=image&tknv=v2&etag=55552f167e163ea9a0d5ccd8da1b9650&rtoken=rjEiDRciqMw1&force_default=yes&ycrid=na-851045768f3dec67ac64ffc396161c98-downloader17f&ts=55863d36261c0&s=a3b890438ce342feda36998eeb03a6dfa6786dc99f86fa91bcc02b23ac53e78b&pb=U2FsdGVkX18qJs9u8KF7Pq9c6APVAoF1rqMDM-WqH_BfEailxIOqwggqLYh0C7XHLpb1UXvDUfOe-DbxJFtcj-Twf2Wpw9mgOiHANMVbS8M="/>
*************
Данная программа предназначена для моделирования ДТП.
*********
### ***Функциональные возможности***

На данный момент программа позволяет моделировать столкновения двух и более автомобилей.
**********
Основной целью программы(***Модели***), является определение конечного положения автомобилей, после их столкновения
*********
![GUI_Modeling_ex](https://1.downloader.disk.yandex.ru/preview/1045ae80d56a9f9bd9cf463c736f5bc3bcb28205622cc25a0a15ed0234e66876/inf/e4yAmOpUdHfB_SQ08sGywc2CX730zv9CQXkRoEITuVEArzK1wcC9_jHBXemtSpedCCtJY9au3z_E3VcYBkHDEw%3D%3D?uid=0&filename=2.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1165x786)
<img src="https://s56f.storage.yandex.net/rdisk/12a3e8386f2ac9572fb6354f64cb5bf2280552cc9b95cdcc06efbb4fb6ad6f59/59adc648/e4yAmOpUdHfB_SQ08sGywXw9MGz52L5W1fUTXNk7tL4uXwXCCpovvzP4aqdVfawyG8NLoD_M6O_ble7u0IqAiA==?uid=227757636&filename=testCrash.gif&disposition=inline&hash=&limit=0&content_type=image%2Fgif&fsize=4200013&hid=d3f9038fcd59546809e8438118c3959b&media_type=image&tknv=v2&etag=434588a9932383579abd10c258d34f8d&rtoken=6Uh6u5xbQVSp&force_default=yes&ycrid=na-7e401904b14e9d6a2235f111e11aeaa3-downloader10e&ts=55863d6c82200&s=3fd87b815655306cb5046739568de43d518dc6e226bd6f054d570a46d5a1ec40&pb=U2FsdGVkX19jHXWTdoMSVCPu8krNEt3z-EI6vV6qng53sMgPJNk0ELwY0MehcPigECx91b0egQgxF3yOJCSmsB5I7S9MCQsHqbTEqytGnxI=" width="1165" height="400" align="center"/>

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

