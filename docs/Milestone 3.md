## Features Added
- Added a priority enumerator with low, medium, and high values
- added task categories
- added priority sorting
- added priority filtering
## Refactoring Improvements
- replaced string based priority values with an enum
- created reusable displaytasklist function
- reduced duplicate display code
- reused priority input logic for adding and filtering tasks
- kept task display responsibilities inside task manager

## Testing Completed
- tested low, medium, high priorities
- tested invalid priority selections
- tested priority sorting
- tested filtering by each priority
- tested filters with no matching tasks
- tested completing tasks after sorting
- tested existing week 2 functionality 
- tested invalid menu input
- tested empt task lists

## GitHub Project Board
- moved add priority and category system from todo to in progress to done
- moved add sorting and filtering from todo, to in progress to done
- moved refactor and display logic and test edge cases from todo to in progress to done
- verified acceptance criteria
- Confirmed the project board matches the current state of the code

## Challenges
- Filtered task numbers do not correspond directly to active task indexes
- completing tasks directly from filtered results is not currently supported
- empty task titles are allowed
## Next Steps
- improve title and category validation
- consider unique IDs for tasks
- add save/load functionality
- consider category filtering or sorting