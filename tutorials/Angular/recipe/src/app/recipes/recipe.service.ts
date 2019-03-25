import { EventEmitter } from '@angular/core';

import { Recipe } from './recipe.model';

export class RecipeService {
  recipeSelected = new EventEmitter<Recipe>();

  private recipes: Recipe[] = [
    new Recipe(
      'A recipe',
      'Simply a test',
      'https://c.pxhere.com/photos/b9/d3/cookbook_recipes_food_cook_book_paper_hand_culinary-881861.jpg!d'
    ),
    new Recipe(
      'A test recipe',
      'Simply test',
      'https://c.pxhere.com/photos/b9/d3/cookbook_recipes_food_cook_book_paper_hand_culinary-881861.jpg!d'
    )
  ];

  getRecipes() {
    return this.recipes.slice();
  }
}
