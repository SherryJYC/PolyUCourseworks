<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Phone</title>
    <style type="text/css">
        <!--
        .Middle {
            text-align: center;
        }

        -->
    </style>
</head>
<body>
<?php
$productArray = array(
    array('name' => 'Samsung Galaxy Note Edge SM-N915P', 'price' => 2234, 'image' => 1),
    array('name' => 'Verizon Wireless Ellipsis 8', 'price' => 2346, 'image' => 2),
    array('name' => 'LG G Pad 7.0', 'price' => 3000, 'image' => 3),
    array('name' => 'LG Transpyre', 'price' => 6936, 'image' => 4),
    array('name' => 'Motorola DROID Turbo', 'price' => 7752, 'image' => 5),
    array('name' => 'HTC Desire 610', 'price' => 5610, 'image' => 6),
    array('name' => 'Motorola Moto X (2014)', 'price' => 5406, 'image' => 7),
    array('name' => 'Kyocera Brigadier', 'price' => 3500, 'image' => 8),
    array('name' => 'Apple iPhone 5s', 'price' => 4200, 'image' => 9),
);
?>
<form action="lab2Order.php" method="post">
    <table width="386" border="1" cellspacing="1" cellpadding="1">

        <?php
        for ($i = 1; $i < 10; $i++) {
            ?>

            <tr>
                <td width="378"><p align="center"><img src="img/<?php echo $i?>.jpg" width="100" height="100"/></p>
                    <p class="Middle"><?php echo $productArray[$i - 1]['name']?><br/>
                        $<?php echo $productArray[$i - 1]['price']?>.00
                    </p>
                    <p class="Middle">Qty:
                        <label>
                            <input type="text" value='0' name="<?php $i ?>" id="<?php $i ?>"/>
                        </label>
                    </p>
                </td>
            </tr>

            <?php
        }
        ?>

        <td class="Middle" bgcolor="#CC99FF"><p>&nbsp;</p>
            <p>Your email address
                <br>
                <label>
                    <input type="text" name="oEmail" id="oEmail"/>
                </label>
            <p>
                <label>
                    <input type="submit" name="button" id="button" value="Submit"/>
                </label>
            </p>
            <p>&nbsp;</p></td>
        </tr>
    </table>
</form>

</body>
</html>