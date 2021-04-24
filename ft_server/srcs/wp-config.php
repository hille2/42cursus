<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '&JaBV1oSF)>[kWsw>&1AM+,tTf]/z*q-gYX,m!+ E%-4zgB9~bMQsqb-dB#z0d+.');
define('SECURE_AUTH_KEY',  '!vSw>xm$E/mt|,g^p^_R8b<c@%dr[iz!.tP9/ L/U|-T_W*6semj19Sn|pPA!uL6');
define('LOGGED_IN_KEY',    ':>O4`8V}I%gScSlit88F:++Lpj^8=(|qo]qGvOVfX*&Z|-tv(+-SB1:hG-O(X8L`');
define('NONCE_KEY',        'JaR81L>+58m]Zv`mmPiD;y>!Y<FOyxk?=)=^tuu,|+tD=X]j]|Ka!W+?cSNSJGX9');
define('AUTH_SALT',        'n_7Cn+iuU+^7|ZNUMx9<HJxP,y9rw0!X=[Bjbpb 3k.GXGRd`Vl6;k&8R>;_+HPx');
define('SECURE_AUTH_SALT', 'K60,QJDwlNwvQK@Fa|QHP2*xoOwB0VzjaCdus:g?,UrMw@zW,I+}G5yL3le[Zo7t');
define('LOGGED_IN_SALT',   ';;Y|&>OOw^vWb2$$!:yD4>J<XDHm%Y[,x2=@qa:_g6~XbouJV0wS.q@p2^2_ au>');
define('NONCE_SALT',       '#|?a|A/%TQqfHU-<_2&qQM|7^dT_yF_bP~2r}vIgnL4wS6>N^$h^^JT?&LYA.zD=');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', true );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
