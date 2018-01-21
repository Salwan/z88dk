#!/usr/bin/perl

# Z88DK Z80 Macro Assembler
#
# Copyright (C) Gunther Strube, InterLogic 1993-99
# Copyright (C) Paulo Custodio, 2011-2017
# License: The Artistic License 2.0, http://www.perlfoundation.org/artistic_license_2_0
# Repository: https://github.com/z88dk/z88dk/
#
# Test https://github.com/z88dk/z88dk/issues/557
# z80asm: consolidated object file erroneously eliminates globally exported defc

use strict;
use warnings;
use v5.10;

use Test::More;

require './t/testlib.pl';

z80asm(<<END, "-b", "", "");
		defc    Lo      = 1
		defc    Lz      = 2
		
		defb 	Lo, Lz
END
check_bin_file("test.bin", pack("C*", 1, 2));

for my $cpu (qw( r2k r3k )) {
	z80asm(<<END, "-b --cpu=$cpu", "", "");
		jp Lz, 0
		jp Lo, 0
END
	check_bin_file("test.bin", pack("C*", 0xE2, 0,0, 0xEA, 0,0));
}

unlink_testfiles();
done_testing();
