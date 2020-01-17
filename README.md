# etaus Random Number Generator

Etaus is a long running random number generator based on the Tausworthe
random number algorithm and a Bays-Durham shuffle.

The period length of the standard taus random number generator
is 2^88 generations, or 10^26 generations.  With the Bays-Durham
shuffle, the period length of etaus approximates 1.2 * 10^61036
generations.

The standard taus random number generator is very strong.  It
passes the dieharder suite of random number tests as well as any
random number generator.  With the Bays-Durham shuffle, the
etaus generator has the same random qualities as the standard
generator.  It uses the same algorithm as the standard algorithm
prior to the shuffle taking place.

The main differences between the etaus generator and the standard
generator are the period length and the unpredictability of each
generation in etaus.

The speed of the etaus generator is equivalent to the speed of
the Mersenne Twister and the standard taus generator.

This generator passes the standard dieharder random number
generator test with the -a parameter.

dieharder -a

The tests in this repository go beyond the dieharder suite
of tests.  In this repository, there are visual tests, not
present in dieharder.  Additional repositories under this
aquila57 account illustrate how the etaus generator can
be tested, in comparison to a wide variety of other random
number generators.

The template test in this repository is different from the
template test in dieharder.  The template test used here
is based on a random pattern.  Each time the test is run
the pattern changes.  The main way to fail the template test
is to duplicate the input data.  The template test fails,
when the template is repeated in its entirety.  Of course,
if the input data is not random, the template test also
fails the chi square test predictably.  Read more about
the template test in TESTING.

Almost all other random number test suites shy away from
running Monte Carlo tests.  Seversl Monte Carlo tests are
included in this repository.  The results of Mersenne
Twister and ranlxd2 are compared to the results of this
generator.  The results of all three generators are very
close and juggle back and forth in each instance of the test.

# Etaus generator subroutines.

The following subroutines are kept in a static subroutine
library, called libetaus.a.

* etausinit - Initialize the etaus random number generator.
This routine is based on date and time.  The generator output
is unpredictable.  See etausstrt for initialization with three
seed parameters.

* etausstrt - Initialize the etaus random number generator with
three seed parameters.  The generator output is repeatable, and
is used for regression testing.  See etausinit for initialization
based on date and time.

* etaus - Generate one 32 bit random unsigned integer with a
uniform distribution.  All other formats of output are based
on this subroutine.

* etausint - Generate a positive random integer between zero
and a limit minus one.

* etauspwr - Generate from 1 to 32 random bits. 

* etausbit - Generate one random bit.

* etausunif - Generate a random fraction from zero to one.
This rountine has 32 bit precision.  See etausfrac() for
a routine with 53 bit precision.  This routine is faster
than etausfrac().

* etausfrac - Generate a random fraction from zero to one.
This rountine has 53 bit precision.  See etausunif() for
a faster routine with 32 bit precision.

* etausdspl - Display the state of the etaus random number
generator.

* etausabt - Write a summary of the copyright and license to
stderr.

# Platforms.

This repository may be compiled under Linux.  Examples are
given for the Debian distribution of Linux.  Download the
zip file for the repository into your private source directory.
Unzip the zip file using unzip.  Change to the master directory.
Chmod the install and de-install scripts.  Run inst.sh to compile.

You may also compile this repository under mingw in Windows.
Instead of initializing etaus with etausinit.c, it is easier
to use etausstrt.c with three initial seeds as parameters.  You
may initialize those seeds with date and time, to make your
testing less predictable.  The XWindows programs in this
repository will not run directly under Microsoft Windows.

See other repositories under this aquila57 account to follow
examples of how to write applications using the etaus random
number generator.

Read INSTALL, TESTING for more information.
