.PHONY: build check clean

dev_name = libringing-dev_0.4.0-5_amd64.deb
bin_name = libringing-bin_0.4.0-5_amd64.deb

build: $(dev_name) $(bin_name)

$(dev_name):
	find libringing-dev -perm 0664 -exec chmod 0644 {} \;
	find libringing-dev -perm 0775 -exec chmod 0755 {} \;
	[ -e libringing-dev/usr/lib/libringing.so       ] || ln -s libringing.so.0.0.0     libringing-dev/usr/lib/libringing.so
	[ -e libringing-dev/usr/lib/libringing.so.0     ] || ln -s libringing.so.0.0.0     libringing-dev/usr/lib/libringing.so.0
	[ -e libringing-dev/usr/lib/libringingcore.so   ] || ln -s libringingcore.so.0.0.0 libringing-dev/usr/lib/libringingcore.so
	[ -e libringing-dev/usr/lib/libringingcore.so.0 ] || ln -s libringingcore.so.0.0.0 libringing-dev/usr/lib/libringingcore.so.0
	fakeroot dpkg-deb --build libringing-dev $(dev_name)

$(bin_name):
	find libringing-bin -perm 0664 -exec chmod 0644 {} \;
	find libringing-bin -perm 0775 -exec chmod 0755 {} \;
	[ -e libringing-bin/usr/bin/gsirilic ] || ln -s gsiril libringing-bin/usr/bin/gsirilic
	[ -e libringing-bin/usr/bin/msiril   ] || ln -s gsiril libringing-bin/usr/bin/msiril
	[ -e libringing-bin/usr/share/man/man1/gsirilic.1.gz ] || ln -s gsiril.1.gz libringing-bin/usr/share/man/man1/gsirilic.1.gz
	[ -e libringing-bin/usr/share/man/man1/msiril.1.gz   ] || ln -s gsiril.1.gz libringing-bin/usr/share/man/man1/msiril.1.gz
	fakeroot dpkg-deb --build libringing-bin $(bin_name)

check: $(dev_name) $(bin_name)
	lintian $(dev_name)
	lintian $(bin_name)

clean:
	rm -f libringing-dev_*_amd64.deb
	rm -f libringing-bin_*_amd64.deb
