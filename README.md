# Algorithm-Design
1. Thuật toán sắp xếp
**a)Sắp xếp chọn - Selection Sort**
Ý tưởng:  Chọn phần tử nhỏ nhất trong n phần tử ban đầu, đưa phần
tử này về vị trí đúng là vị trí đầu tiên a[0] của mảng hiện hành. Sau đó không quan tâm đến nó nữa, xem mảng hiện hành chỉ còn n-1 phần tử của mảng ban đầu. Bắt đầu từ vị trí thứ 2, lặp lại quá trình trên cho
mảng hiện hành đến khi chỉ còn 1 phần tử.
Độ phức tạp: T(n) = O(n^2)
<img width="662" height="397" alt="image" src="https://github.com/user-attachments/assets/5faca714-2181-4756-bc5a-c1cf47f5aae7" />
**b)Sắp xếp xen - Insertion Sort**
Ý tưởng: Bắt chước cách sắp xếp quân bài của những người chơi bài. Muốn sắp một bộ bài theo trật tự, người chơi bài rút lần lượt từ quân bài thứ 2, so với các quân đứng trước nó để chèn vào vị trí thích hợp
<img width="627" height="397" alt="image" src="https://github.com/user-attachments/assets/532c8c4f-f291-4353-a4cc-9a5fa4af83d0" />
**c)Sắp xếp "nổi bọt" - Bubble Sort**
Ý tưởng : 
Xuất phát từ cuối (hoặc đầu) mảng, đổi chổ các cặp phần tử kế cận để đưa phần tử nhỏ (lớn) hơn trong cặp phần tử đó về vị trí đúng đầu (cuối) mảng hiện hành. Sau đó sẽ không xét đến nó ở vị trí tiếp theo, do vậy ở lần xử lý thứ i sẽ có vị trí đầu mảng là i. Lặp lại xử lý trên cho đến
khi không còn cặp phần tử nào để xét.
Giải thuật:
Bước 1: Xét các a[j] (j giảm từ n-1 đến 1), so sánh khoá của a[j] với khoá của a[j-1]. Nếu a[j] < a[j-1] thì đổi a[j] và a[j-1]. Sau bước này thì a[0] có khoá nhỏ nhất.
 Bước 2: Xét các a[j] (j giảm từ n-1 đến 2), so sánh khoá của a[j] với khoá của a[j-1]. Nếu a[j] < a[j-1] thì đổi a[j] và a[j-1]. Sau bước này thì a[1] có khoá nhỏ thứ 2.
Bước n-1: mảng đã được sắp thứ tự.
<img width="693" height="417" alt="image" src="https://github.com/user-attachments/assets/7e04b069-5d9c-49a2-a5d3-63e967fd06aa" />
**d)Quicksort**
- Chọn chốt: chọn phần tử lớn nhất trong 2 phân tử có khóa khác nhau đầu tiên. khóa bằng nhau hết hoặc chỉ có một phần tử thì không có chốt => dừng
- Phân hoạch dãy a[0] .. a[n-1] thành hai mảng con "bêntrái" và "bên phải".
Mảng con "bên trái" bao gồm các phần tử có khóa nhỏ hơn chốt. (L <v)
Mảng con "bên phải" bao gồm các phần tử có khóa lớn hơn hoặc bằng chốt. (R>= v)
1. L chạy sang phải tới khi gặp phần tử có khóa ≥ chốt
2. Cho R chạy sang trái tới khi gặp phần tử có khóa < chốt
3. Tại chỗ dừng của L và R: nếu L < R thì hoán vị a[L], a[R].
   <img width="503" height="433" alt="image" src="https://github.com/user-attachments/assets/305d1516-a312-4ada-bea0-0d68e699e670" />

Lặp lại cho đến khi L > R => phân hoạch
Kết quả sắp xếp: 1 2 4 5 5 8 8 10 12 15
3. thuật toán tham ăn
4. Nhánh cận
5. 
