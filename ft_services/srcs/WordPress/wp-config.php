<?php

define( 'DB_NAME', 'wordpress' );
define( 'DB_USER', 'admin' );
define( 'DB_PASSWORD', '0000' );
define( 'DB_HOST', 'mysql-svc' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );
define('AUTH_KEY',         '&JaBV1oSF)>[kWsw>&1AM+,tTf]/z*q-gYX,m!+ E%-4zgB9~bMQsqb-dB#z0d+.');
define('SECURE_AUTH_KEY',  '!vSw>xm$E/mt|,g^p^_R8b<c@%dr[iz!.tP9/ L/U|-T_W*6semj19Sn|pPA!uL6');
define('LOGGED_IN_KEY',    ':>O4`8V}I%gScSlit88F:++Lpj^8=(|qo]qGvOVfX*&Z|-tv(+-SB1:hG-O(X8L`');
define('NONCE_KEY',        'JaR81L>+58m]Zv`mmPiD;y>!Y<FOyxk?=)=^tuu,|+tD=X]j]|Ka!W+?cSNSJGX9');
define('AUTH_SALT',        'n_7Cn+iuU+^7|ZNUMx9<HJxP,y9rw0!X=[Bjbpb 3k.GXGRd`Vl6;k&8R>;_+HPx');
define('SECURE_AUTH_SALT', 'K60,QJDwlNwvQK@Fa|QHP2*xoOwB0VzjaCdus:g?,UrMw@zW,I+}G5yL3le[Zo7t');
define('LOGGED_IN_SALT',   ';;Y|&>OOw^vWb2$$!:yD4>J<XDHm%Y[,x2=@qa:_g6~XbouJV0wS.q@p2^2_ au>');
define('NONCE_SALT',       '#|?a|A/%TQqfHU-<_2&qQM|7^dT_yF_bP~2r}vIgnL4wS6>N^$h^^JT?&LYA.zD=');

$table_prefix = 'wp_';

define( 'WP_DEBUG', true );
if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', __DIR__ . '/' );
}

require_once ABSPATH . 'wp-settings.php';