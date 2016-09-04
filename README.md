Entity-Component-System Library
===============================

**Experimental & work-in-progress** C++14 multithreaded compile-time entity-component-system library.

Successful development of complex real-time applications and games requires a flexible and efficient
entity management system. As a project becomes more intricate, it’s critical to find an elegant way
to compose objects in order to pre-vent code repetition, improve modularity and open up powerful
optimization possibilities.

The Entity-Component-System architectural pattern was designed to achieve the aforementioned
benefits, by separating data from logic.
• Entities 1 can be composed of small, reusable, and generic components;
• Components can be stored in contiguous memory areas, thus improving data locality and cache-
friendliness;
• Application logic can be easily parallelized and abstracted away from the objects themselves and
their storage policies;
• The state of the application can be serialized and shared over the network with less effort;
• A more modular, generic and easily-testable codebase.

**"ecst"** was developed as my BCS graduation project.

* [Build Instructions](BUILD_INSTRUCTIONS.md)
* [Code Sample](CODE_SAMPLE.md
* [Accompanying Thesis](https://github.com/SuperV1234/bcs_thesis)
* [Slides](https://github.com/SuperV1234/cppnow2016)
 * NOTE: These are accompanying an earlier version of the library was that presented at **C++Now
2016**pdf
* [LICENSE](LICENSE)

---------------------------------------------------------------------------------------------------
# Demonstration of using ECST
---------------------------------------------------------------------------------------------------
# ecst FAQ #

## Logging in and Storing Credentials ##

### How do I store credentials? ###

If you want to save a user's login details for next time, do not store their password directly. Instead, implement the `SPSessionDelegate` method: 

For example:
