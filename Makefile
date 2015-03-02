.PHONY: build check clean

dev_name = libringing-dev_0.4.0-4_amd64.deb
bin_name = libringing-bin_0.4.0-4_amd64.deb

build: $(dev_name) $(bin_name)

$(dev_name):
	find ringing-lib-dev -perm 0664 -exec chmod 0644 {} \;
	find ringing-lib-dev -perm 0775 -exec chmod 0755 {} \;
	[ -e ringing-lib-dev/usr/lib/libringing.so       ] || ln -s libringing.so.0.0.0     ringing-lib-dev/usr/lib/libringing.so
	[ -e ringing-lib-dev/usr/lib/libringing.so.0     ] || ln -s libringing.so.0.0.0     ringing-lib-dev/usr/lib/libringing.so.0
	[ -e ringing-lib-dev/usr/lib/libringingcore.so   ] || ln -s libringingcore.so.0.0.0 ringing-lib-dev/usr/lib/libringingcore.so
	[ -e ringing-lib-dev/usr/lib/libringingcore.so.0 ] || ln -s libringingcore.so.0.0.0 ringing-lib-dev/usr/lib/libringingcore.so.0
	fakeroot dpkg-deb --build ringing-lib-dev $(dev_name)

$(bin_name):
	find ringing-lib-bin -perm 0664 -exec chmod 0644 {} \;
	find ringing-lib-bin -perm 0775 -exec chmod 0755 {} \;
	[ -e ringing-lib-bin/usr/bin/gsirilic ] || ln -s gsiril ringing-lib-bin/usr/bin/gsirilic
	[ -e ringing-lib-bin/usr/bin/msiril   ] || ln -s gsiril ringing-lib-bin/usr/bin/msiril
	fakeroot dpkg-deb --build ringing-lib-bin $(bin_name)

check: $(dev_name) $(bin_name)
	lintian $(dev_name)
	lintian $(bin_name)

clean:
	rm -f libringing-dev_*_amd64.deb
	rm -f libringing-bin_*_amd64.deb
