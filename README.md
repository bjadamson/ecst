Entity-Component-System Library (Header Only !!)
================================================

**Experimental & work-in-progress** C++14 multithreaded compile-time entity-component-system library.

Successful development of complex real-time applications and games requires a flexible and efficient
entity management system. As a project becomes more intricate, it’s critical to find an elegant way
to compose objects in order to prevent code repetition, improve modularity and open up powerful
optimization possibilities.

The Entity-Component-System architectural pattern was designed to achieve the aforementioned
benefits, by separating data from logic.

* Entities can be composed of small, reusable, and generic components.
* Components can be stored in contiguous memory areas, thus improving data locality and cache-
friendliness.
* Application logic can be easily parallelized and abstracted away from the objects themselves and
their storage policies.
* The state of the application can be serialized and shared over the network with less effort.
* A more modular, generic and easily-testable codebase.

**"ecst"** was developed as my BCS graduation project.

---------------------------------------------------------------------------------------------------
# Getting Started
* [Build Instructions](BUILD_INSTRUCTIONS.md)
* [Code Sample](CODE_SAMPLE.md)
* [LICENSE](LICENSE)

---------------------------------------------------------------------------------------------------
# More Information
* [Accompanying Thesis](https://github.com/SuperV1234/bcs_thesis)
* [Slides](https://github.com/SuperV1234/cppnow2016)
 * NOTE: These are accompanying an earlier version of the library was that presented at **C++Now
2016**pdf

---------------------------------------------------------------------------------------------------
# FAQ #

**Q:** Can we have components that aren't default constructible?

**A:** This has come up before in the past, and no. More information can be found in the [original
issue.](https://github.com/SuperV1234/ecst/issues/8)



**Q:** I'm trying to **read/write to/from** my component, but I'm getting a compilation error. What
is happening?

**A:** Systems need to indicate (statically) which components that system will read from / write
too. You do this when your defining your "system signature list".
[more info](https://github.com/SuperV1234/ecst/issues/4)

---------------------------------------------------------------------------------------------------
# More Links
* [Current Issues](https://github.com/SuperV1234/ecst/issues)
* [Resolved Issues](https://github.com/SuperV1234/ecst/issues?q=is%3Aissue+is%3Aclosed)
