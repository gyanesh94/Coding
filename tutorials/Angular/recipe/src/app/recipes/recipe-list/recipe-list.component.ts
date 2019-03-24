import { Component, OnInit } from '@angular/core';
import { Recipe } from '../recipe.model';

@Component({
  selector: 'app-recipe-list',
  templateUrl: './recipe-list.component.html',
  styleUrls: ['./recipe-list.component.css']
})
export class RecipeListComponent implements OnInit {
  recipes: Recipe[] = [
    new Recipe('A test recipe', 'Simply a test', 'https://c.pxhere.com/photos/b9/d3/cookbook_recipes_food_cook_book_paper_hand_culinary-881861.jpg!d'),
    new Recipe('A test recipe', 'Simply a test', 'https://c.pxhere.com/photos/b9/d3/cookbook_recipes_food_cook_book_paper_hand_culinary-881861.jpg!d')
  ];

  constructor() { }

  ngOnInit() {
  }

}
