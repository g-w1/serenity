#!/usr/bin/env -S bash ../.port_include.sh
port=libtool
version=2.4
useconfigure="true"
depends="bash sed"
files="https://ftp.gnu.org/gnu/libtool/libtool-${version}.tar.xz libtool-${version}.tar.xz
https://ftp.gnu.org/gnu/libtool/libtool-${version}.tar.xz.sig libtool-${version}.tar.xz.sig
https://ftp.gnu.org/gnu/gnu-keyring.gpg gnu-keyring.gpg"
auth_type="sig"
auth_opts="--keyring ./gnu-keyring.gpg libtool-${version}.tar.xz.sig"
configopts="--prefix=/usr/local"

post_install() {
    mkdir -p "${SERENITY_BUILD_DIR}/Root/usr/bin"
    ln -sf /usr/local/bin/sed "${SERENITY_BUILD_DIR}/Root/usr/bin/sed"
}
