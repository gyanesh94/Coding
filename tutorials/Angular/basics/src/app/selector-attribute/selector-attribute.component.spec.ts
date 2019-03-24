import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { SelectorAttributeComponent } from './selector-attribute.component';

describe('SelectorAttributeComponent', () => {
  let component: SelectorAttributeComponent;
  let fixture: ComponentFixture<SelectorAttributeComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ SelectorAttributeComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(SelectorAttributeComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
