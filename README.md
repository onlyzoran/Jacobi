# Jacobi (Метод Якоби)

## Описание функций

1. `void __fastcall TForm1::FormCreate(TObject *Sender)` - функция запускается при создании формы (главной формы). В теле функции устанавливается начальное значение количества строк и столбцов для StringGrid1 (таблица для ввода значений), расставляются заголовки StringGrid1 (x1, x2 … y) и устанавливается текущая вкладка в PageControl1.

2. `void __fastcall TForm1::CSpinEdit1Change(TObject *Sender)` - функция запускается при изменении значения объекта CSpinEdit1 (размер матрицы). Таблица StringGrid1 меняет свой размер в зависимости от нового значения CSpinEdit1 а также заново расставляются заголовки (x1, x2 … y).

3. `void __fastcall TForm1::N11Click(TObject *Sender)` - функция запускается при нажатии правой кнопки мыши и выборе значения “Вариант 1” в контекстном меню. Объект CSpinEdit1 получает базовое значение “3”, таблица StringGrid1 получает размер из этого значения и заполняется базовыми значениями (они нужны для быстрой проверки программы).

4. `void __fastcall TForm1::Button1Click(TObject *Sender)` - функция запускается при нажатии кнопки Button1 (Вычислить). Основная вычислительная функция программы.

5. `void __fastcall TForm1::Button3Click(TObject *Sender)` - функция запускается при нажатии кнопки Button3 (Закрыть). Закрывается форма (главная форма) и программа. В начале тела функции проверяются все ячейки StringGrid1 на заполненность, если таблица полностью заполнена, то выполняются дальнейшие вычисления, если нет, то выводится сообщение об ошибке. В начале система приводится к нормальному виду и выводится в поле Memo1. Затем значения приводятся в виде матрицы в таблицах StringGrid3 (a) и StringGrid4 (b). После этого начинается процесс итераций и при достижении условия с заданной точность процеес останавливается. Значения x, e и eMax записываются в таблицу StringGrid5. Результирующие значения записываются в StringGrid6. Количество итераций записывается в поле Edit2 (Число итераций).

6. `void __fastcall TForm1::Button2Click(TObject *Sender)` - функция запускается при нажатии кнопки Button2 (Очистить). Очищаются от значений таблицы StringGrid1, StringGrid3, StringGrid4, StringGrid5, StringGrid6, поле Memo1 (Приведенная система) и поле Edit2 (Число итераций).