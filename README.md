# DSS

<h2>Интерфейс для вывода и ввода информации для работы экспертной системы </h2> 

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

<b>База знаний</b> организована с использованием формата TXT, который является наиболее знакомым пользователю для понимания и изменения. При нажатии на кнопку «База знаний» будет выведено окно со всеми файлами, которые содержат данные базы знаний. 
Был реализован модуль объяснения решения. 

При нажатии на кнопку «Объяснение решения» будет выведено окно с вопросами и ответами, которые были даны на них, которые удовлетворяют выбранному системой решению. 

При нажатии на кнопку «Справка» будет выведено окно с объяснением работы экспертной системы. Во время работы экспертной системы это окно будет содержать список из гипотезы, вопроса и тех утверждений, что на данный момент проверяет экспертная система (рис. 3). 
