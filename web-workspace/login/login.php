<?php
  session_start();
  $connect = mysql_connect("localhost","hjshin","1234") or die ("fail");
  $dn_con = mysql_select_db("hjshin_db",$connect);
  $id=$_GET['id'];
  $pw=$_GET['pw'];

  $query = "select * from user where id ='$id'";
  $result = $connect -> query($query);

  if(mysql_num_row($result)==1){
    $row=mysql_fetch_row($result);

    if($row['pw']==$pw){
      $_SESSION['id']=$id;
      if(isset($_SESSION['id']))
      ?>
      <script>
        alert("로그인 성공!");
      </script>
<?php
}
else {
  ?>
  <script>
    alert("로그인 실패!");
  </script>
  <?php
}
?>
