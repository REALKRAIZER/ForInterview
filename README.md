# ForInterview
TasksFromTheBook - задачи, которые я решал, изучая стивена пратта

NotStupidCalculator - проект на ~450 строк кода на плюсах(и чуть-чуть QT)

Калькулятор не очень глупый, потому что:
- Его можно относительно легко расширить засчет добавления новых операций в класс Operations.
- Калькулятор может считать длинные выражения, это достигается благодаря тому, что строка с выражением разбивается по стекам на операции и операнды, приводя выражение к польской нотации

 Также в проекте используется шаблон MVC, который реализуется через паттерн 'Наблюдатель', поэтому интерфейс независим от данных(я не использовал для этого инструменты QT).
