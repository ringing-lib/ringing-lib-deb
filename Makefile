.PHONY: check clean

libringing-dev_0.4.0-1_amd64.deb:
	find src -perm 0664 -exec chmod 0644 {} \;
	find src -perm 0775 -exec chmod 0755 {} \;
	[ -e src/usr/lib/libringing.so       ] || ln -s libringing.so.0.0.0     src/usr/lib/libringing.so
	[ -e src/usr/lib/libringing.so.0     ] || ln -s libringing.so.0.0.0     src/usr/lib/libringing.so.0
	[ -e src/usr/lib/libringingcore.so   ] || ln -s libringingcore.so.0.0.0 src/usr/lib/libringingcore.so
	[ -e src/usr/lib/libringingcore.so.0 ] || ln -s libringingcore.so.0.0.0 src/usr/lib/libringingcore.so.0
	fakeroot dpkg-deb --build src libringing-dev_0.4.0-1_amd64.deb

check: libringing-dev_0.4.0-1_amd64.deb
	lintian libringing-dev_0.4.0-1_amd64.deb

clean:
	rm libringing-dev_0.4.0-1_amd64.deb
