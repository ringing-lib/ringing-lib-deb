.PHONY: check clean

deb_name = libringing-dev_0.4.0-2_amd64.deb

$(deb_name):
	find src -perm 0664 -exec chmod 0644 {} \;
	find src -perm 0775 -exec chmod 0755 {} \;
	[ -e src/usr/lib/libringing.so       ] || ln -s libringing.so.0.0.0     src/usr/lib/libringing.so
	[ -e src/usr/lib/libringing.so.0     ] || ln -s libringing.so.0.0.0     src/usr/lib/libringing.so.0
	[ -e src/usr/lib/libringingcore.so   ] || ln -s libringingcore.so.0.0.0 src/usr/lib/libringingcore.so
	[ -e src/usr/lib/libringingcore.so.0 ] || ln -s libringingcore.so.0.0.0 src/usr/lib/libringingcore.so.0
	fakeroot dpkg-deb --build src $(deb_name)

check: $(deb_name)
	lintian $(deb_name)

clean:
	rm -f libringing-dev_*_amd64.deb
