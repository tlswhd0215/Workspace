<html>
<head>
  <meta charset="utf-8">
  <title>점수 합계와 평균</title>
</head>
<body>
  <?
    $kor=80;
    $eng=70;
    $math=90;
    $sum=$kor+$eng+$math;
    $ave=$sum/3;

    echo "
    <table border ='1'>
    <th colspan='2'>홍길동의 점수</th>
    <tr><td>국어</td>
    <td>$kor</td></tr>
    <tr><td>영어</td>
    <td>$eng</td></tr>
    <tr><td>수학</td>
    <td>$math</td></tr>
    <tr><td>총점</td>
    <td>$sum</td></tr>
    </tr><td>평균</td>
    <td>$ave</td></tr>
    </table>
    ";
  ?>
</body>
</html>
