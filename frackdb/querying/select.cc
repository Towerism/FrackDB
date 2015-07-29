#include <algorithm>
#include "select.hh"

Select::Select(Evaluator* evaluator) : evaluator(evaluator) {
}

Relation Select::execute(const Relation& relation) {
  Relation view = relation;
  view.remove_if_not(evaluator);
  return view;
}
