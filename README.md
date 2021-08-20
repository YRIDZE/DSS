# DSS

<h2>Экспертная система </h2> 

<b>Математические методы:</b> 
1. Теорема Карлина, преобразование (1) , весовые коэффициенты задаются пользователем в виде константных значений
2. Теорема Гермейера, преобразование (2) , весовые коэффициенты задаются пользователем в виде константных значений
3. Метод ограничений, преобразование (1)
4. Метод ограничений, преобразование (2)
5. Метод взвешенных сумм с точечным оцениванием весов

<b>Стратегия вывода:</b> обратный вывод

<b>Тип экспертной системы:</b> продукционный

<b>Язык программирования:</b> С++

<b>Модуль чтения продукционных правил</b> из строковых данных поддерживает операторы «ИЛИ», «И», «НЕ», а также задание порядка выполнения операций с помощью скобок. 

<b>База знаний</b> организована с использованием формата TXT, который является наиболее знакомым пользователю для понимания и изменения. При нажатии на кнопку «База знаний» выводится окно со всеми файлами, которые содержат данные базы знаний. 
Реализован модуль объяснения решения. 

При нажатии на кнопку «Объяснение решения» выводится окно с вопросами и выбраными на них ответами, которые удовлетворяют выбранному системой решению. 

При нажатии на кнопку «Справка» выводится окно с объяснением работы экспертной системы. Во время работы экспертной системы это окно содержит список из гипотезы, вопроса и тех утверждений, что на данный момент проверяет экспертная система. 
